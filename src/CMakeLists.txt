add_executable(template_project
    main.cpp
)

target_include_directories(template_project
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
) 