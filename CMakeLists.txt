cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
# include cmake/utils.cmake
include(utils)


## Harfbuzz - ICU-Common - UCDN - Freetype2 ##
##############################################
set(HARFBUZZ_BUILD_ICU ON CACHE BOOL "Enable building of ICU")
set(HARFBUZZ_BUILD_UCDN ON CACHE BOOL "Enable building of UCDN")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/hb-icu-ft)

message(STATUS "harfbuzz" ${HARFBUZZ_LIBRARIES})

set(ALFONS_DEPS_LIBRARIES
  ${ALFONS_DEPS_LIBRARIES}
  harfbuzz ${HARFBUZZ_LIBRARIES}
  CACHE INTERNAL "alfons-libs" FORCE)

set(GLM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glm)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/alfons)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
