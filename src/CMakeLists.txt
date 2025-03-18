add_executable(template_project
    main.cpp
    platform/platform_factory.cpp
)

# 添加平台特定的实现
if(WIN32)
    target_sources(template_project PRIVATE
        platform/windows/windows_platform.cpp
    )
elseif(APPLE)
    target_sources(template_project PRIVATE
        platform/macos/macos_platform.cpp
    )
elseif(UNIX AND NOT APPLE)
    target_sources(template_project PRIVATE
        platform/linux/linux_platform.cpp
    )
else()
    target_sources(template_project PRIVATE
        platform/generic/generic_platform.cpp
    )
endif()

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