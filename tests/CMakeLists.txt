add_executable(template_project_tests
    main_test.cpp
)

target_link_libraries(template_project_tests
    PRIVATE
        GTest::gtest
        GTest::gtest_main
        fmt::fmt
        spdlog::spdlog
        nlohmann_json::nlohmann_json
)

add_test(NAME template_project_tests COMMAND template_project_tests) 