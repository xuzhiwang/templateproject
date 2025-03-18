#include "platform/macos/macos_platform.h"
#include <array>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>

#include <sys/types.h>
#include <sys/sysctl.h>

namespace TemplateProject {
namespace Platform {

class MacOSPlatform::Impl {
public:
    Impl() = default;
    ~Impl() = default;

    std::string getSystemVersion() const {
        std::array<char, 128> buffer{};
        size_t size = buffer.size();
        
        if (sysctlbyname("kern.osrelease", buffer.data(), &size, nullptr, 0) == 0) {
            return std::string(buffer.data(), size);
        }
        
        return "Unknown";
    }
    
    std::string executeShellCommand(const std::string& command) const {
        std::array<char, 128> buffer{};
        std::string result;
        
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        
        return result;
    }
};

MacOSPlatform::MacOSPlatform() : pImpl(std::make_unique<Impl>()) {}

MacOSPlatform::~MacOSPlatform() = default;

bool MacOSPlatform::initialize() {
    // 初始化 macOS 平台特定功能
    return true;
}

void MacOSPlatform::cleanup() {
    // 清理 macOS 平台特定资源
}

std::string MacOSPlatform::getPlatformName() const {
    return "macOS";
}

std::string MacOSPlatform::getPlatformVersion() const {
    return pImpl->getSystemVersion();
}

std::string MacOSPlatform::executeCommand(const std::string& command) const {
    return pImpl->executeShellCommand(command);
}

} // namespace Platform
} // namespace TemplateProject 