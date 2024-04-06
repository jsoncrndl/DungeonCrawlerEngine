cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME DungeonCrawlerEngine)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(${PROJECT_NAME})

# List files
set(SOURCE_FILES 
    src/engine/engine.cpp
    src/engine/sdl_event_dispatcher.cpp
    src/engine/math/math_types.cpp

    # Resources
    src/engine/resource/registry.cpp
    src/engine/resource/texture_importer.cpp
    src/engine/resource/shader_importer.cpp
    src/engine/resource/material_importer.cpp
    src/engine/resource/asset_manager.cpp

    # Input

    # Graphics
    src/engine/graphics/graphics.cpp
    src/engine/graphics/render_pipeline.cpp
    src/engine/graphics/game_window.cpp
    src/engine/graphics/sprite.cpp
    src/engine/graphics/texture.cpp
    src/engine/graphics/render_texture.cpp
    src/engine/graphics/quad.cpp
    src/engine/graphics/material.cpp
    src/engine/graphics/shader.cpp

    # Game
    src/engine/game/game.cpp
    src/engine/game/level/level.cpp
    src/engine/game/states/game_state.cpp
    src/engine/game/states/gs_loading.cpp
    src/engine/game/states/gs_level.cpp
    src/engine/game/free_resource_visitor.cpp
    src/engine/game/reset_object_visitor.cpp
    src/engine/game/pooled_object.cpp
    src/engine/game/object_pool.cpp
    src/engine/game/pooled_object_visitor.cpp

    # ECS
    src/engine/game/memory_pool.cpp

    # Entites
    src/engine/game/ecs/entities/entity.cpp

    # Components
    src/engine/game/ecs/components/component.cpp
    src/engine/game/ecs/components/component_registry.cpp

    src/engine/game/ecs/components/transform.cpp

    # Systems
    src/engine/game/ecs/systems/system.cpp
)

set(HEADER_FILES 
    src/engine/engine.h
    src/engine/sdl_event_dispatcher.h
    src/engine/math/math_types.h

    # Resources
    src/engine/resource/fileio.h
    src/engine/resource/registry.h
    src/engine/resource/texture_importer.h
    src/engine/resource/shader_importer.h
    src/engine/resource/material_importer.h
    src/engine/resource/asset_manager.h

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
    src/engine/graphics/material.h
    src/engine/graphics/shader.h

    # Game
    src/engine/game/game.h
    src/engine/game/level/level.h
    src/engine/game/states/game_state.h
    src/engine/game/states/gs_loading.h
    src/engine/game/states/gs_level.h
    src/engine/game/pooled_object.h
    src/engine/game/object_pool.h
    src/engine/game/reset_object_visitor.h
    src/engine/game/free_resource_visitor.h
    src/engine/game/pooled_object_visitor.h

    # ECS
    src/engine/game/memory_pool.h

    # Entities
    src/engine/game/ecs/entities/entity.h

    # Components
    src/engine/game/ecs/components/component.h
    src/engine/game/ecs/components/component_registry.h
    src/engine/game/ecs/components/transform.h

    # Systems
    src/engine/game/ecs/systems/system.h
)

source_group(TREE "${CMAKE_SOURCE_DIR}/src" PREFIX "Source Files" FILES ${SOURCE_FILES})
source_group(TREE "${CMAKE_SOURCE_DIR}/src" PREFIX "Header Files" FILES ${HEADER_FILES})

# include(FetchContent)

# FetchContent_Declare(
#   luau
#   GIT_REPOSITORY https://github.com/luau-lang/luau.git
#   GIT_TAG        47ad768c69ca1995fa9c2fb3b18fab6d0f02527b # 0.619
# )

# FetchContent_MakeAvailable(luau)


# Include packages

find_package(GameNetworkingSockets REQUIRED)
find_package(GLEW REQUIRED)
find_package(RapidJSON CONFIG REQUIRED)
find_package(rttr CONFIG REQUIRED)
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
target_link_libraries(${PROJECT_NAME} PRIVATE rapidjson)
target_link_libraries(${PROJECT_NAME} PRIVATE RTTR::Core)
# target_link_libraries(${PROJECT_NAME} PRIVATE luau)

# Copy resources on build
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/resources
                ${CMAKE_CURRENT_BINARY_DIR}/resources)