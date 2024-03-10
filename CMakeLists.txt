cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME DungeonCrawlerEngine)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(${PROJECT_NAME})

# List files
set(SOURCE_FILES 
    src/engine/game.cpp

    # Input
    src/engine/input/input.cpp

    # Graphics
    src/engine/graphics/graphics.cpp
    src/engine/graphics/render_pipeline.cpp
    src/engine/graphics/game_window.cpp
)

set(HEADER_FILES 
    src/engine/game.h

    # Input
    src/engine/input/input.h

    # Graphics
    src/engine/graphics/graphics.h
    src/engine/graphics/render_pipeline.h
    src/engine/graphics/game_window.h
)

source_group(TREE "${CMAKE_SOURCE_DIR}/src" PREFIX "Source Files" FILES ${SOURCE_FILES})
source_group(TREE "${CMAKE_SOURCE_DIR}/src" PREFIX "Header Files" FILES ${HEADER_FILES})

# Include SDL
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include GameNetworkingSockets
find_package(GameNetworkingSockets REQUIRED)



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

# Add SDL to target

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE GameNetworkingSockets::shared)