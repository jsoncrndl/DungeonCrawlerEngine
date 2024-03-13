cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME DungeonCrawlerEngine)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(${PROJECT_NAME})

# List files
set(SOURCE_FILES 
    src/engine/game.cpp
    src/engine/sdl_event_dispatcher.cpp
    src/engine/fileio.cpp

    # Input
    src/engine/input/input.cpp

    # Graphics
    src/engine/graphics/graphics.cpp
    src/engine/graphics/render_pipeline.cpp
    src/engine/graphics/game_window.cpp
    src/engine/graphics/sprite.cpp
    src/engine/graphics/texture.cpp
    src/engine/graphics/render_texture.cpp
    src/engine/graphics/quad.cpp
)

set(HEADER_FILES 
    src/engine/game.h
    src/engine/sdl_event_dispatcher.h
    src/engine/math/math_types.h
    src/engine/fileio.h

    # Input
    src/engine/input/input.h

    # Graphics
    src/engine/graphics/graphics.h
    src/engine/graphics/render_pipeline.h
    src/engine/graphics/game_window.h
    src/engine/graphics/sprite.h
    src/engine/graphics/texture.h
    src/engine/graphics/render_texture.h
    src/engine/graphics/quad.h
)

source_group(TREE "${CMAKE_SOURCE_DIR}/src" PREFIX "Source Files" FILES ${SOURCE_FILES})
source_group(TREE "${CMAKE_SOURCE_DIR}/src" PREFIX "Header Files" FILES ${HEADER_FILES})

# Include packages

find_package(GameNetworkingSockets REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Build project
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} src/main.cpp)

# Compiler Specific Options (Extra warnings)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -O3)
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

# Add SDL to target

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE GameNetworkingSockets::shared)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image::SDL2_image)

# Copy resources on build
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/resources
                ${CMAKE_CURRENT_BINARY_DIR}/resources)