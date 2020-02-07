cmake_minimum_required(VERSION 3.15)
project(RayTracing)

set(CMAKE_CXX_STANDARD 20)

set(RayTracer_Sources
        "src/architecture.cpp"
        "src/layout.cpp"
        "src/norm_4.cpp"
        "src/vec_4.cpp"
        "src/vector_buffer.cpp")

add_library(RayTracer ${RayTracer_Sources})

target_include_directories(RayTracer
        PUBLIC
            include/)

target_compile_options(RayTracer
        PRIVATE
            -fPIC

            -Wall
            -Wextra
            -Wpedantic

            -Werror-switch
            -Werror-return-type
            -Werror-shadow)

add_executable(PathTracer "main.cpp")

target_link_libraries(PathTracer
        PUBLIC
            RayTracer)