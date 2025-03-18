#include "platform/platform.h"
#include "platform/platform_detect.h"

#include <memory>
#include <stdexcept>

#if PLATFORM_WINDOWS
#include "platform/windows/windows_platform.h"
#elif PLATFORM_MACOS
#include "platform/macos/macos_platform.h"
#elif PLATFORM_LINUX
#include "platform/linux/linux_platform.h"
#else
#include "platform/generic/generic_platform.h"
#endif

namespace TemplateProject {
namespace Platform {

std::unique_ptr<PlatformInterface> createPlatform() {
#if PLATFORM_WINDOWS
    return std::make_unique<WindowsPlatform>();
#elif PLATFORM_MACOS
    return std::make_unique<MacOSPlatform>();
#elif PLATFORM_LINUX
    return std::make_unique<LinuxPlatform>();
#else
    return std::make_unique<GenericPlatform>();
#endif
}

} // namespace Platform
} // namespace TemplateProject 