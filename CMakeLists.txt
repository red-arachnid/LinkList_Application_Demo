cmake_minimum_required(VERSION 3.28)
project(linklist_project LANGUAGES CXX)

find_package(Slint REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
slint_target_sources(${PROJECT_NAME} ui/app.slint)
target_link_libraries(${PROJECT_NAME} PRIVATE Slint::Slint)

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}> COMMAND_EXPAND_LISTS)
    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY WIN32_EXECUTABLE TRUE)
endif()