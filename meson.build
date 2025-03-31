project(
    'chk_engine',
    'c',
    version: '0.1.0',
    license: 'MIT',
    meson_version: '>=1.3.0',
    default_options: ['c_std=c11'],
)

compiler = meson.get_compiler('c')
if compiler.get_id() == 'msvc'
    add_global_arguments('/Zc:preprocessor', language: 'c')
endif

inc = include_directories('include')

#
# CHK_CORE
#

cwalk_dep = dependency(
    'cwalk',
    fallback: ['cwalk', 'cwalk_dep'],
)

chk_core_lib = library(
    'chk_core',
    [
        'src/chk/core/fmt.c',
        'src/chk/core/log.c',
    ],
    include_directories: inc,
    c_shared_args: ['-DCORE_DLL', '-DCORE_DLL_EXPORTS'],
    dependencies: [cwalk_dep],
    gnu_symbol_visibility: 'hidden',
    install: true,
)

chk_core_dep = declare_dependency(
    include_directories: inc,
    link_with: chk_core_lib,
)

install_headers(
    [
        'include/chk/core/dll.h',
        'include/chk/core/dllbase.h',

        'include/chk/core/callback.h',
        'include/chk/core/core.h',
        'include/chk/core/fmt.h',
        'include/chk/core/log.h',
        'include/chk/core/types.h',
        'include/chk/core/utils.h',
    ],
    subdir: 'chk/core',
)

#
# CHK_CODE
#

dl_dep = dependency(
    'dl',
    fallback: ['dlfcn-win32', 'dlfcn_win32_dep'],
)

chk_code_lib = library(
    'chk_code',
    [
        'src/chk/code/code.c',
    ],
    include_directories: inc,
    c_shared_args: ['-DCODE_DLL', '-DCODE_DLL_EXPORTS'],
    dependencies: [dl_dep],
    gnu_symbol_visibility: 'hidden',
    install: true,
)

chk_code_dep = declare_dependency(
    include_directories: inc,
    link_with: chk_code_lib,
)

install_headers(
    [
        'include/chk/code/dll.h',

        'include/chk/code/code.h',
    ],
    subdir: 'chk/code',
)

#
# CHK_WINDOW
#

glfw_dep = dependency(
    'glfw',
    fallback: ['glfw', 'glfw_dep'],
    default_options: ['examples=false', 'install=true', 'tests=false'],
)

chk_window_lib = library(
    'chk_window',
    [
        'src/chk/window/window.c',
    ],
    include_directories: inc,
    c_shared_args: ['-DWINDOW_DLL', '-DWINDOW_DLL_EXPORTS'],
    dependencies: [glfw_dep],
    gnu_symbol_visibility: 'hidden',
    install: true,
)

chk_window_dep = declare_dependency(
    include_directories: inc,
    link_with: chk_window_lib,
)

install_headers(
    [
        'include/chk/window/dll.h',

        'include/chk/window/window.h',
    ],
    subdir: 'chk/window',
)

#
# CHK_DRAW
#

epoxy_dep = dependency(
    'epoxy',
    fallback: ['epoxy', 'libepoxy_dep'],
    default_options: ['docs=false', 'tests=false'],
)

chk_draw_lib = library(
    'chk_draw',
    [
        'src/chk/draw/apply.c',
        'src/chk/draw/draw.c',
        'src/chk/draw/push.c',
    ],
    include_directories: inc,
    c_shared_args: ['-DDRAW_DLL', '-DDRAW_DLL_EXPORTS'],
    dependencies: [epoxy_dep],
    gnu_symbol_visibility: 'hidden',
    install: true,
)

chk_draw_dep = declare_dependency(
    include_directories: inc,
    link_with: chk_draw_lib,
)

install_headers(
    [
        'include/chk/draw/dll.h',

        'include/chk/draw/draw.h',
    ],
    subdir: 'chk/draw',
)

#
# CHK_LAUNCHER
#

executable(
    'chk_launcher',
    ['src/chk/launcher/main.c'],
    dependencies: [chk_core_dep, chk_code_dep, chk_window_dep, chk_draw_dep],
    include_directories: inc,
    install: true,
)