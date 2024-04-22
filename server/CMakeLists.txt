add_executable(dce-server main.cpp)

set_property(TARGET dce-server PROPERTY CXX_STANDARD 20)

# Compiler Specific Options (Extra warnings)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(dce-server PRIVATE /W4 /permissive-)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(dce-server PRIVATE -Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(dce-server PRIVATE -Wall -Wextra -pedantic -O3)
endif()

target_link_libraries(dce-server engine)
target_compile_definitions(engine PRIVATE DCE_DEDICATED_SERVER=1)