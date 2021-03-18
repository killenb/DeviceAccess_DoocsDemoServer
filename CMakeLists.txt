CMAKE_MINIMUM_REQUIRED(VERSION 3.5.1)

SET(PROJECT_BASE_NAME oven)
PROJECT(${PROJECT_BASE_NAME}_server)

SET(${PROJECT_NAME}_MAJOR_VERSION 00)
SET(${PROJECT_NAME}_MINOR_VERSION 00)
SET(${PROJECT_NAME}_PATCH_VERSION 00)
include(${CMAKE_SOURCE_DIR}/cmake/set_version_numbers.cmake)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

INCLUDE(${CMAKE_SOURCE_DIR}/cmake/set_default_build_to_release.cmake)
INCLUDE(${CMAKE_SOURCE_DIR}/cmake/set_default_flags.cmake)

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include(${CMAKE_SOURCE_DIR}/cmake/add_dependency.cmake)
add_dependency(DOOCS 20.10.1 server REQUIRED)
add_dependency(ChimeraTK-DeviceAccess 02.02 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src server_sources)

add_executable(${PROJECT_NAME} ${server_sources})
target_link_libraries(${PROJECT_NAME} ${DOOCS_LIBRARIES} ${ChimeraTK-DeviceAccess_LIBRARIES})

FILE(COPY config/oven_server.conf config/oven.map config/oven.dmap DESTINATION ${PROJECT_BINARY_DIR})

# Install the executabe and the config template
#if("${CMAKE_INSTALL_PREFIX}" STREQUAL "/export/doocs/server")
#  install(PROGRAMS ${PROJECT_BINARY_DIR}/${PROJECT_NAME} DESTINATION ${PROJECT_BASE_NAME}_server RENAME ${PROJECT_BASE_NAME}_server.dist)
#  install(FILES config/RPC_LIBNO config/qlset_CONF.TEMPLATE DESTINATION ${PROJECT_BASE_NAME}_server)
#else()
#  install(PROGRAMS ${PROJECT_BINARY_DIR}/${PROJECT_NAME} DESTINATION share/${PROJECT_BASE_NAME}_server)
#  install(FILES config/RPC_LIBNO config/qlset_CONF.TEMPLATE DESTINATION share/${PROJECT_BASE_NAME}_server)
#endif()
