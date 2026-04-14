cmake_minimum_required(VERSION 3.16)

project(exam_task2_clock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(glfw3 QUIET)
if (glfw3_FOUND)
    if (TARGET glfw)
        target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
    elseif (TARGET glfw3::glfw)
        target_link_libraries(${PROJECT_NAME} PRIVATE glfw3::glfw)
    else()
        message(FATAL_ERROR "glfw3 найден, но CMake target не известен (ожидал glfw или glfw3::glfw)")
    endif()
else()
    if (WIN32)
        # Cross-compile: не используем pkg-config (иначе легко подцепить linux .pc и смешать хедеры).
        find_path(GLFW3_INCLUDE_DIR GLFW/glfw3.h
            HINTS
                /usr/x86_64-w64-mingw32/include
                /usr/x86_64-w64-mingw32/sys-root/mingw/include
        )
        find_library(GLFW3_LIBRARY NAMES glfw3 glfw
            HINTS
                /usr/x86_64-w64-mingw32/lib
                /usr/x86_64-w64-mingw32/sys-root/mingw/lib
        )
        if (GLFW3_INCLUDE_DIR AND GLFW3_LIBRARY)
            target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW3_INCLUDE_DIR})
            target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW3_LIBRARY} gdi32 user32 shell32)
        elseif (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../glfw/CMakeLists.txt")
            message(STATUS "MinGW GLFW not found - using ../glfw subdirectory")
            set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
            set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
            set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
            if (NOT TARGET glfw)
                add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../glfw ${CMAKE_BINARY_DIR}/glfw)
            endif()
            target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
        else()
            message(FATAL_ERROR "Не найдены Windows-заголовки/библиотека GLFW для MinGW. Установи пакет MinGW GLFW или добавь исходники GLFW в exam/glfw.")
        endif()
    elseif (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../glfw/CMakeLists.txt")
        message(STATUS "System GLFW3 not found - using ../glfw subdirectory")
        set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
        set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
        set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        if (NOT TARGET glfw)
            add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../glfw ${CMAKE_BINARY_DIR}/glfw)
        endif()
        target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
    else()
        message(FATAL_ERROR "GLFW не найден. На Linux поставь glfw3-devel, на Windows/vcpkg установи glfw3, или добавь исходники в exam/glfw")
    endif()
endif()

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

