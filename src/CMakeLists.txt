add_executable(template_project
    main.cpp
)

target_include_directories(template_project
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(template_project
    PRIVATE
        fmt::fmt
        spdlog::spdlog
        nlohmann_json::nlohmann_json
) 