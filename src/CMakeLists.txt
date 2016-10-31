set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1y")

add_executable(basic
  basic.cpp)

target_link_libraries(basic
  LINK_PUBLIC
  alfons
  alfons_render)
