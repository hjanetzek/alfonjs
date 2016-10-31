#   -DCMAKE_BUILD_TYPE=<Debug|RelWithDebInfo|Release|MinSizeRel>

mkdir -p build
cd build

cmake -DCMAKE_TOOLCHAIN_FILE=cmake/emscripten.toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" ..
