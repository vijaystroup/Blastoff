cmake_minimum_required(VERSION 3.18)
project(BlastOff VERSION 1.0.0)

add_compile_options(--config /Users/vijay/cpp/.config/clang++_config.txt)
add_link_options(--config /Users/vijay/cpp/.config/clang++_config.txt)
link_libraries(
    -lfmt
)
add_executable(
    main
    main.cpp
)
