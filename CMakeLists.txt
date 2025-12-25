cmake_minimum_required(VERSION 3.7)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(DungeonCrawlerEngine)

# Include packages

find_package(crossguid CONFIG REQUIRED)
find_package(GameNetworkingSockets REQUIRED)
find_package(GLEW REQUIRED)
find_package(RapidJSON CONFIG REQUIRED)
find_package(rttr CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2 REQUIRED)
find_package(EASTL CONFIG REQUIRED)
find_package(unofficial-minizip CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# include(FetchContent)

# FetchContent_Declare(
#   luau
#   GIT_REPOSITORY https://github.com/luau-lang/luau.git
#   GIT_TAG        47ad768c69ca1995fa9c2fb3b18fab6d0f02527b # 0.619
# )

# FetchContent_MakeAvailable(luau)

add_subdirectory(engine)
add_subdirectory(server)
add_subdirectory(player)
add_subdirectory(editor)