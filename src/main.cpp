#include <iostream>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include "platform/platform.h"

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
    
    // 使用平台抽象层
    auto platform = TemplateProject::Platform::createPlatform();
    if (platform->initialize()) {
        spdlog::info("Platform initialization successful");
        
        // 获取平台信息
        std::string platformName = platform->getPlatformName();
        std::string platformVersion = platform->getPlatformVersion();
        
        fmt::print("Running on {} version {}\n", platformName, platformVersion);
        
        // 执行系统命令示例
        try {
            std::string result = platform->executeCommand("uname -a");
            fmt::print("Command result: {}", result);
        } catch (const std::exception& e) {
            spdlog::error("Failed to execute command: {}", e.what());
        }
        
        platform->cleanup();
    } else {
        spdlog::error("Platform initialization failed");
    }
    
    return 0;
} 