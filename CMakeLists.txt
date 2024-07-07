cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine2D)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SDL_DIR "${CMAKE_SOURCE_DIR}/libs/SDL")
set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/libs/imgui")

add_subdirectory(${SDL_DIR})
add_subdirectory(${IMGUI_DIR})

file(GLOB SOURCES "src/*.cpp")
add_library(PhysicsEngine2D ${SOURCES})
target_include_directories(PhysicsEngine2D PUBLIC include)
target_include_directories(PhysicsEngine2D PUBLIC ${SDL_DIR}/include)
target_include_directories(PhysicsEngine2D PUBLIC ${IMGUI_DIR})
target_include_directories(PhysicsEngine2D PUBLIC ${IMGUI_DIR}/backends)

target_link_libraries(PhysicsEngine2D SDL3::SDL3 imgui-sdl3 imgui-sdlrenderer3)

add_executable(main main.cpp)
target_include_directories(main PUBLIC include)
target_link_libraries(main PhysicsEngine2D)