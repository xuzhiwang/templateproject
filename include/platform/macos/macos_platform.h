#pragma once

#include "platform/platform.h"
#include <string>

namespace TemplateProject {
namespace Platform {

class MacOSPlatform : public PlatformInterface {
public:
    MacOSPlatform();
    ~MacOSPlatform() override;
    
    bool initialize() override;
    void cleanup() override;
    
    std::string getPlatformName() const override;
    std::string getPlatformVersion() const override;
    std::string executeCommand(const std::string& command) const override;

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

} // namespace Platform
} // namespace TemplateProject 