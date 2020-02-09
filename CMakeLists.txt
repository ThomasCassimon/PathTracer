cmake_minimum_required(VERSION 3.15)
project(RayTracing)

find_package(Stb REQUIRED)

set(CMAKE_CXX_STANDARD 20)

set(PathTracing_Sources
        "src/architecture.cpp"
		"src/frame_buffer.cpp"
        "src/layout.cpp"
		"src/norm_3.cpp"
        "src/norm_4.cpp"
		"src/stb_image_impl.c"
        "src/vec_3.cpp"
        "src/vec_4.cpp"
        "src/vector_buffer.cpp")

add_library(PathTracing ${PathTracing_Sources})

target_include_directories(PathTracing
        PRIVATE
		${Stb_INCLUDE_DIR}
		PUBLIC
        include/)

target_compile_options(PathTracing
        PUBLIC
        -mavx2

        PRIVATE
        -fPIC

        -Wall
        -Wextra
        -Wpedantic

        -Werror-switch
        -Werror-return-type
        -Werror-shadow)

add_subdirectory(app)
add_subdirectory(test)