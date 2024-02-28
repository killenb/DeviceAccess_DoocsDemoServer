project ('oven',
    'cpp',
    meson_version : '>=0.49'
)

src = [
    'src/EqFctOven.cpp',
    'src/main.cpp',
]

incdir = include_directories('include')

# Things we install besides the binary
datafiles = [
    'config/oven.dmap',
    'config/oven.map',
    'config/oven_server.conf',
]
# Also put the data to the build directory so you can run the server there
configure_file(input : 'config/oven.dmap',
  output : 'oven.dmap',
  copy: true)
configure_file(input : 'config/oven.map',
  output : 'oven.map',
  copy: true)
configure_file(input : 'config/oven_server.conf',
  output : 'oven_server.conf',
  copy: true)

# Libraries we depend on
dep = [
    dependency('doocs-serverlib'),
    dependency('ChimeraTK-DeviceAccess', method: 'cmake', modules: ['ChimeraTK::ChimeraTK-DeviceAccess']),
    meson.get_compiler('cpp').find_library('atomic', required:true)
]

# The server executable
executable(meson.project_name() + '_server',
    [src],
    dependencies : dep,
    install : true,
    include_directories : incdir
)

install_data(datafiles,
    install_dir : get_option('datadir'),
)

# vi:ts=4:sw=4:sts=4:et:ft=conf
