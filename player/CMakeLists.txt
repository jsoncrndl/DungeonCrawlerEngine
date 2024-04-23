add_executable(DungeonCrawlerEngine main.cpp)

set_property(TARGET DungeonCrawlerEngine PROPERTY CXX_STANDARD 20)

# Compiler Specific Options (Extra warnings)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(DungeonCrawlerEngine PRIVATE /W4 /permissive-)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(DungeonCrawlerEngine PRIVATE -Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(DungeonCrawlerEngine PRIVATE -Wall -Wextra -pedantic -O3)
endif()

# target_compile_definitions(DungeonCrawlerEngine PRIVATE DCE_DEDICATED_SERVER=0)
target_link_libraries(DungeonCrawlerEngine engine)

# Copy resources on build
add_custom_command(
        TARGET DungeonCrawlerEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/resources
                ${CMAKE_CURRENT_BINARY_DIR}/resources)
