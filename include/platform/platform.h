#pragma once

#include <memory>
#include <string>

namespace TemplateProject {
namespace Platform {

/**
 * 平台抽象层接口
 * 用于隔离不同平台的特定实现
 */
class PlatformInterface {
public:
    virtual ~PlatformInterface() = default;
    
    /**
     * 初始化平台相关资源
     * @return 初始化是否成功
     */
    virtual bool initialize() = 0;
    
    /**
     * 释放平台相关资源
     */
    virtual void cleanup() = 0;
    
    /**
     * 获取平台名称
     * @return 平台名称
     */
    virtual std::string getPlatformName() const = 0;
    
    /**
     * 获取平台版本
     * @return 平台版本
     */
    virtual std::string getPlatformVersion() const = 0;
    
    /**
     * 执行平台特定命令
     * @param command 要执行的命令
     * @return 命令执行结果
     */
    virtual std::string executeCommand(const std::string& command) const = 0;
};

/**
 * 工厂函数 - 创建当前平台的实现
 * @return 平台实现实例
 */
std::unique_ptr<PlatformInterface> createPlatform();

} // namespace Platform
} // namespace TemplateProject 