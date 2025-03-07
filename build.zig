const std = @import("std");

const version: std.SemanticVersion = .{ .major = 1, .minor = 7, .patch = 0 };

pub fn build(b: *std.Build) void {
    const upstream = b.dependency("libxkbcommon", .{});
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const linkage = b.option(std.builtin.LinkMode, "linkage", "Link mode") orelse .static;
    const strip = b.option(bool, "strip", "Omit debug information");
    const pic = b.option(bool, "pie", "Produce Position Independent Code");

    // if (version.major != 1) {
    //     // The versioning used for the shared libraries assumes that the major
    //     // version of xkbcommon as a whole will increase to 2 if and only if there
    //     // is an ABI break, at which point we should probably bump the SONAME of
    //     // all libraries to .so.2.
    //     @compileError("We probably need to bump the SONAME of libxkbcommon");
    // }
    // // To avoid an unnecessary SONAME bump, xkbcommon 1.x.y produces
    // // libxkbcommon.so.0.x.y, libxkbcommon-x11.so.0.x.y, libxkbregistry.so.0.x.y.
    // const soname_version: std.SemanticVersion = .{
    //     .major = 0,
    //     .minor = version.minor,
    //     .patch = version.patch,
    //     .pre = version.pre,
    //     .build = version.build,
    // };
    const soname_version: std.SemanticVersion = .{ .major = 0, .minor = 0, .patch = 0 };

    // Most of these config options have not been tested.

    const xkb_config_root = b.option([]const u8, "xkb-config-root", "The XKB config root") orelse b.pathJoin(&.{ b.install_prefix, "share/X11/xkb" });
    const xkb_config_extra_path = b.option([]const u8, "xkb-config-extra-path", "Extra lookup path for system-wide XKB data [default=$sysconfdir/xkb]") orelse "/etc/xkb";
    const x_locale_root = b.option([]const u8, "x-locale-root", "The X locale root [default=$datadir/X11/locale]") orelse b.pathJoin(&.{ b.install_prefix, "share/X11/locale" });
    // const bash_completion_path = b.option([]const u8, "bash-completion-path", "Directory for bash completion scripts");
    const default_rules = b.option([]const u8, "default-rules", "Default XKB ruleset") orelse "evdev";
    const default_model = b.option([]const u8, "default-model", "Default XKB model") orelse "pc105";
    const default_layout = b.option([]const u8, "default-layout", "Default XKB layout") orelse "us";
    const default_variant = b.option([]const u8, "default-variant", "Default XKB variant");
    const default_options = b.option([]const u8, "default-options", "Default XKB options");
    // const enable_tools = b.option(bool, "enable-tools", "Enable building tools") orelse true;
    const enable_x11 = b.option(bool, "enable-x11", "Enable building the xkbcommon-x11 library") orelse true;
    // const enable_docs = b.option(bool, "enable-docs", "Enable building the documentation") orelse false;
    // const enable_cool_uris = b.option(bool, "enable-cool-uris", "Enable creating redirections to maintain stable documentation pages") orelse false;
    // const enable_wayland = b.option(bool, "enable-wayland", "nable support for Wayland utility programs (requires enable-tools)") orelse true;
    const enable_xkbregistry = b.option(bool, "enable-xkbregistry", "Enable building libxkbregistry") orelse true;
    // const enable_bash_completion = b.option(bool, "enable-bash-completion", "Enable installing bash completion scripts") orelse true;

    const config_header = b.addConfigHeader(.{}, .{
        .EXIT_INVALID_USAGE = 2,
        .LIBXKBCOMMON_VERSION = b.fmt("{}", .{version}),
        .LIBXKBCOMMON_TOOL_PATH = b.pathJoin(&.{ b.install_prefix, "libexec/xkbcommon" }),
        ._GNU_SOURCE = 1,
        .DFLT_XKB_CONFIG_ROOT = xkb_config_root,
        .DFLT_XKB_CONFIG_EXTRA_PATH = xkb_config_extra_path,
        .XLOCALEDIR = x_locale_root,
        .DEFAULT_XKB_RULES = default_rules,
        .DEFAULT_XKB_MODEL = default_model,
        .DEFAULT_XKB_LAYOUT = default_layout,
        // .DEFAULT_XKB_VARIANT
        // .DEFAULT_XKB_OPTIONS
        .HAVE_UNISTD_H = 1,
        .HAVE___BUILTIN_EXPECT = 1,
        .HAVE_EACCESS = 1,
        .HAVE_EUIDACCESS = 1,
        .HAVE_MMAP = 1,
        .HAVE_MKOSTEMP = 1,
        .HAVE_POSIX_FALLOCATE = 1,
        .HAVE_STRNDUP = 1,
        .HAVE_ASPRINTF = 1,
        // .HAVE_VASPRINTF = 1,
        .HAVE_SECURE_GETENV = 1,
        // .HAVE___SECURE_GETENV = 1,
        .PATH_MAX = @as(i64, if (target.result.os.tag == .windows) 260 else 4096),
    });
    if (default_variant) |variant| {
        config_header.addValues(.{ .DEFAULT_XKB_VARIANT = variant });
    } else {
        config_header.addValues(.{ .DEFAULT_XKB_VARIANT = .NULL });
    }
    if (default_options) |options| {
        config_header.addValues(.{ .DEFAULT_XKB_OPTIONS = options });
    } else {
        config_header.addValues(.{ .DEFAULT_XKB_OPTIONS = .NULL });
    }

    const generated_parser = generateParser(b, upstream);

    const update_parser = b.step("update-parser", "Updated parser.c and parser.h (requires bison or byacc)");
    if (generated_parser) |generated| {
        const generated_parser_c, const generated_parser_h = generated;

        const update = b.addUpdateSourceFiles();
        update_parser.dependOn(&update.step);
        update.addCopyFileToSource(generated_parser_c, "parser.c");
        update.addCopyFileToSource(generated_parser_h, "parser.h");
    } else {
        update_parser.addError("unable to find bison or byacc in $PATH or search prefixes (--search-prefix)", .{}) catch {};
        update_parser.addError("parser.c and parser.h could not be updated", .{}) catch {};
    }

    const use_system_bison = b.systemIntegrationOption("bison", .{});
    const parser_c: std.Build.LazyPath, const parser_h: std.Build.LazyPath = if (use_system_bison)
        generated_parser orelse {
            std.log.err("Could not find a compatible YACC program (bison or byacc)", .{});
            return;
        }
    else
        .{ b.path("parser.c"), b.path("parser.h") };

    const xkbcommon = b.addLibrary(.{
        .linkage = linkage,
        .name = "xkbcommon",
        .version = soname_version,
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
            .link_libc = true,
            .strip = strip,
            .pic = pic,
        }),
    });
    xkbcommon.root_module.addCSourceFiles(.{
        .files = libxkbcommon_sources,
        .root = upstream.path(""),
        .flags = cflags,
    });
    xkbcommon.root_module.sanitize_c = false;
    xkbcommon.root_module.addConfigHeader(config_header);
    xkbcommon.root_module.addCSourceFile(.{ .file = parser_c });
    xkbcommon.root_module.addIncludePath(parser_h.dirname());
    xkbcommon.installHeader(upstream.path("include/xkbcommon/xkbcommon.h"), "xkbcommon/xkbcommon.h");
    xkbcommon.installHeader(upstream.path("include/xkbcommon/xkbcommon-compat.h"), "xkbcommon/xkbcommon-compat.h");
    xkbcommon.installHeader(upstream.path("include/xkbcommon/xkbcommon-compose.h"), "xkbcommon/xkbcommon-compose.h");
    xkbcommon.installHeader(upstream.path("include/xkbcommon/xkbcommon-keysyms.h"), "xkbcommon/xkbcommon-keysyms.h");
    xkbcommon.installHeader(upstream.path("include/xkbcommon/xkbcommon-names.h"), "xkbcommon/xkbcommon-names.h");
    xkbcommon.root_module.addIncludePath(upstream.path("src"));
    xkbcommon.root_module.addIncludePath(upstream.path("include"));
    xkbcommon.version_script = upstream.path("xkbcommon.map");
    b.installArtifact(xkbcommon);

    if (enable_x11) {
        const libxkbcommon_x11 = b.addLibrary(.{
            .linkage = linkage,
            .name = "xkbcommon-x11",
            .version = soname_version,
            .root_module = b.createModule(.{
                .target = target,
                .optimize = optimize,
                .link_libc = true,
                .strip = strip,
                .pic = pic,
            }),
        });
        libxkbcommon_x11.root_module.linkSystemLibrary("xcb", .{}); // TODO
        libxkbcommon_x11.root_module.linkSystemLibrary("xcb-xkb", .{}); // TODO
        libxkbcommon_x11.root_module.addCSourceFiles(.{
            .files = libxkbcommon_x11_sources,
            .root = upstream.path(""),
            .flags = cflags,
        });
        libxkbcommon_x11.root_module.addConfigHeader(config_header);
        libxkbcommon_x11.installHeader(upstream.path("include/xkbcommon/xkbcommon-x11.h"), "xkbcommon/xkbcommon-x11.h");
        libxkbcommon_x11.root_module.addIncludePath(upstream.path("src"));
        libxkbcommon_x11.root_module.addIncludePath(upstream.path("include"));
        libxkbcommon_x11.version_script = upstream.path("xkbcommon-x11.map");
        b.installArtifact(libxkbcommon_x11);
    }

    if (enable_xkbregistry) {
        const libxkbregistry = b.addLibrary(.{
            .linkage = linkage,
            .name = "xkbregistry",
            .version = soname_version,
            .root_module = b.createModule(.{
                .target = target,
                .optimize = optimize,
                .link_libc = true,
                .strip = strip,
                .pic = pic,
            }),
        });
        libxkbregistry.root_module.addCSourceFiles(.{
            .files = libxkbregistry_sources,
            .root = upstream.path(""),
            .flags = cflags,
        });
        libxkbregistry.root_module.addConfigHeader(config_header);
        libxkbregistry.installHeader(upstream.path("include/xkbcommon/xkbregistry.h"), "xkbcommon/xkbregistry.h");
        libxkbregistry.root_module.addIncludePath(upstream.path("src"));
        libxkbregistry.root_module.addIncludePath(upstream.path("include"));
        libxkbregistry.version_script = upstream.path("xkbregistry.map");
        b.installArtifact(libxkbregistry);

        const link_system_libxml = b.systemIntegrationOption("libxml2", .{});
        if (link_system_libxml) {
            libxkbregistry.root_module.linkSystemLibrary("libxml-2.0", .{});
        } else if (b.lazyDependency("libxml2", .{
            .target = target,
            .optimize = optimize,
            .minimum = true,
            .valid = true,
            .sax1 = true,
        })) |libxml2| {
            libxkbregistry.root_module.linkLibrary(libxml2.artifact("xml"));
        }
    }
}

fn generateParser(
    b: *std.Build,
    upstream: *std.Build.Dependency,
) ?struct { std.Build.LazyPath, std.Build.LazyPath } {
    const exe, const kind: enum { bison, byacc } = if (b.findProgram(&.{ "bison", "win_bison" }, &.{}) catch null) |bison|
        .{ bison, .bison }
    else if (b.findProgram(&.{"byacc"}, &.{}) catch null) |byacc|
        .{ byacc, .byacc }
    else
        return null;

    const parser_write_files = b.addWriteFiles();
    _ = parser_write_files.addCopyFile(upstream.path("src/xkbcomp/parser.y"), "parser.y");

    const run_step = std.Build.Step.Run.create(b, b.fmt("run {s}", .{@tagName(kind)}));
    run_step.setCwd(parser_write_files.getDirectory());
    run_step.addFileArg(.{ .cwd_relative = exe });

    switch (kind) {
        .bison => {
            _ = run_step.addArg("--defines=parser.h");
        },
        .byacc => {
            run_step.addArgs(&.{ "-H", "parser.h" });
        },
    }

    run_step.addArg("-o");
    const parser_c = run_step.addOutputFileArg("parser.c");
    run_step.addArgs(&.{ "-p", "_xkbcommon_", "--no-lines" });
    run_step.addFileArg(upstream.path("src/xkbcomp/parser.y"));

    const write_header = b.addWriteFiles();
    write_header.step.dependOn(&run_step.step);
    const parser_h = write_header.addCopyFile(
        .{ .generated = .{ .file = &parser_write_files.generated_directory, .sub_path = "parser.h" } },
        "parser.h",
    );

    return .{ parser_c, parser_h };
}

const cflags: []const []const u8 = &.{
    "-fno-strict-aliasing",
    "-Wno-unused-parameter",
    "-Wno-missing-field-initializers",
    "-Wpointer-arith",
    "-Wmissing-declarations",
    "-Wformat=2",
    "-Wstrict-prototypes",
    "-Wmissing-prototypes",
    "-Wnested-externs",
    "-Wbad-function-cast",
    "-Wshadow",
    // "-Wlogical-op",
    "-Wdate-time",
    "-Wwrite-strings",
    "-Wno-documentation-deprecated-sync",
};

const libxkbcommon_sources: []const []const u8 = &.{
    "src/compose/parser.c",
    "src/compose/paths.c",
    "src/compose/state.c",
    "src/compose/table.c",
    "src/xkbcomp/action.c",
    "src/xkbcomp/ast-build.c",
    "src/xkbcomp/compat.c",
    "src/xkbcomp/expr.c",
    "src/xkbcomp/include.c",
    "src/xkbcomp/keycodes.c",
    "src/xkbcomp/keymap.c",
    "src/xkbcomp/keymap-dump.c",
    "src/xkbcomp/keywords.c",
    "src/xkbcomp/rules.c",
    "src/xkbcomp/scanner.c",
    "src/xkbcomp/symbols.c",
    "src/xkbcomp/types.c",
    "src/xkbcomp/vmod.c",
    "src/xkbcomp/xkbcomp.c",
    "src/atom.c",
    "src/context.c",
    "src/context-priv.c",
    "src/keysym.c",
    "src/keysym-utf.c",
    "src/keymap.c",
    "src/keymap-priv.c",
    "src/state.c",
    "src/text.c",
    "src/utf8.c",
    "src/utils.c",
};

const libxkbcommon_x11_sources: []const []const u8 = &.{
    "src/x11/keymap.c",
    "src/x11/state.c",
    "src/x11/util.c",
    "src/context-priv.c",
    "src/keymap-priv.c",
    "src/atom.c",
};

const libxkbregistry_sources: []const []const u8 = &.{
    "src/registry.c",
    "src/utils.c",
    "src/util-list.c",
};
