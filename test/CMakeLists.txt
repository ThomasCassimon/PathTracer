set(Test_Sources
        "src/main.cpp")

add_executable(Test ${Test_Sources})

target_link_libraries(Test
        PUBLIC
        PathTracing)