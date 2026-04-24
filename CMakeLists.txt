cmake_minimum_required(VERSION 3.28)
project(linklist_project LANGUAGES CXX)

find_package(Slint REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
slint_target_sources(${PROJECT_NAME} ui/app.slint)
target_link_libraries(${PROJECT_NAME} PRIVATE Slint::Slint)

if (WIN32)
    add_custom_command(TARGET my_application POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:my_application> $<TARGET_FILE_DIR:my_application> COMMAND_EXPAND_LISTS)
endif()