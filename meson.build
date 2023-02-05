project(
  'simp-cli',
  'cpp',
  version : '0.1',
  default_options : ['warning_level=3']
)

simp_cli_lib = shared_library(
  'simp-cli',
  'src/simp_cli/callback.cpp',
  'src/simp_cli/simp_cli.cpp',
  include_directories : include_directories('include'),
)

simp_cli_dep = declare_dependency(
  include_directories : include_directories('include'),
  link_with : simp_cli_lib,
)

if not meson.is_subproject()
  exe = executable(
    'simp-cli',
    'src/main.cpp',
    dependencies : [simp_cli_dep]
  )
endif