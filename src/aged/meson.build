# src/aged/meson.build

# Define include directories - need libsystemd_includes for sd-bus.h, sd-event.h,
# etc., and src/shared for main-func.h.
aged_includes = [libsystemd_includes, include_directories('.', '../shared')]

aged_bypass_sources = files(
        'aged_bypass.c',
)

agectl_sources = files(
        'agectl.c',
)

# Create a static library for integration with the main daemon
# Note: We must include config.h for build-time macros like SD_BOOT, HAVE_WARNING_*,
# RELATIVE_SOURCE_PATH, etc. that are needed by fundamental headers.
# Note: AGED_BYPASS_INTEGRATED=1 tells the source to skip the standalone main() function
# to avoid duplicate symbol conflicts when linking into the systemd daemon.
libaged_bypass = static_library(
        'aged-bypass',
        aged_bypass_sources,
        include_directories : aged_includes,
        c_args : ['-DAGED_BYPASS_ENABLED', '-DAGED_BYPASS_INTEGRATED', '-include', 'config.h'],
)

# Add to global sources for linking with daemon
sources += libaged_bypass

# Keep the standalone executable for testing
# Note: Do NOT include 'include_directories' here - the main meson.build
# handles adding the source directory automatically, and using += on
# IncludeDirs objects is not supported in Meson.
executables += [
        executable_template + {
                'name' : 'aged-bypass',
                'public' : true,
                'sources' : aged_bypass_sources,
        },
        executable_template + {
                'name' : 'agectl',
                'public' : true,
                'sources' : agectl_sources,
        },
]
