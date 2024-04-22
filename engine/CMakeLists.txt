set(SOURCE_FILES 
    src/engine/engine.cpp
    src/engine/sdl_event_dispatcher.cpp
    src/engine/math/math_types.cpp

    # Memory
    src/engine/memory/permanent_allocator.cpp

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
    src/engine/game/level/level_deserializer.cpp
    src/engine/game/states/gs_loading.cpp
    src/engine/game/states/gs_level.cpp

    src/engine/game/serializable.cpp

    # ECS

    # Entites
    src/engine/game/ecs/entities/entity.cpp

    # Components
    src/engine/game/ecs/components/component.cpp
    src/engine/game/ecs/components/component_factory.cpp

    src/engine/game/ecs/components/transform.cpp

    # Systems
    src/engine/game/ecs/systems/system.cpp
)

set(HEADER_FILES 
    src/engine/engine.h
    src/engine/sdl_event_dispatcher.h
    src/engine/math/math_types.h

    # Memory
    src/engine/memory/permanent_allocator.h
    src/engine/memory/byte_literals.h
    src/engine/memory/memory_types.h
    src/engine/memory/pool_allocator.h

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
    src/engine/game/level/level_deserializer.h
    src/engine/game/states/gs_loading.h
    src/engine/game/states/gs_level.h
    
    src/engine/game/serializable.h
    
    # ECS

    # Entities
    src/engine/game/ecs/entities/entity.h

    # Components
    src/engine/game/ecs/components/component.h
    src/engine/game/ecs/components/component_factory.h
    src/engine/game/ecs/components/transform.h

    # Systems
    src/engine/game/ecs/systems/system.h
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "Source Files" FILES ${SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "Header Files" FILES ${HEADER_FILES})

add_library(engine ${SOURCE_FILES} ${HEADER_FILES})

set_property(TARGET engine PROPERTY CXX_STANDARD 20)

# Compiler Specific Options (Extra warnings)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(engine PUBLIC /W4 /permissive-)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(engine PUBLIC -Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(engine PUBLIC -Wall -Wextra -pedantic -O3)
endif()

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(engine PUBLIC SDL2::SDL2main)
endif()

# Link libraries
target_link_libraries(engine PUBLIC SDL2::SDL2)
target_link_libraries(engine PUBLIC GameNetworkingSockets::shared)
target_link_libraries(engine PUBLIC GLEW::GLEW)
target_link_libraries(engine PUBLIC SDL2_image::SDL2_image)
target_link_libraries(engine PUBLIC rapidjson)
target_link_libraries(engine PUBLIC RTTR::Core)
target_link_libraries(engine PUBLIC EASTL)
target_link_libraries(engine PUBLIC crossguid)
# target_link_libraries(engine PUBLIC luau)

target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_definitions(engine PRIVATE DCE_DEDICATED_SERVER=0)