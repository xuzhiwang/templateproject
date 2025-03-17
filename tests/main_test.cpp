#include <gtest/gtest.h>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

TEST(BasicTest, FormatTest) {
    EXPECT_EQ(fmt::format("{}", "test"), "test");
}

TEST(JsonTest, BasicJson) {
    nlohmann::json j = {
        {"name", "test"}
    };
    EXPECT_EQ(j["name"], "test");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 