 find_package(Catch2 CONFIG REQUIRED)

 set(Test_Sources
         "src/main.cpp")

 add_executable(Test ${Test_Sources})

 target_link_libraries(Test
         PUBLIC
         Catch2::Catch2
         PathTracing)