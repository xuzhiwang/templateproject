#include <iostream>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

int main() {
    // 使用 fmt 进行格式化输出
    fmt::print("Hello from fmt!\n");
    
    // 使用 spdlog 进行日志输出
    spdlog::info("Hello from spdlog!");
    
    // 使用 nlohmann/json 创建 JSON 对象
    nlohmann::json j = {
        {"name", "Template Project"},
        {"version", "1.0.0"}
    };
    
    std::cout << "JSON output: " << j.dump(4) << std::endl;
    
    return 0;
} 