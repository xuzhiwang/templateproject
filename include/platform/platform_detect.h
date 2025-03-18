#pragma once

/**
 * 平台检测宏
 * 用于在编译时确定当前平台
 */

// 操作系统检测
#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS 1
#elif defined(__APPLE__) && defined(__MACH__)
    #define PLATFORM_MACOS 1
#elif defined(__linux__)
    #define PLATFORM_LINUX 1
#elif defined(__ANDROID__)
    #define PLATFORM_ANDROID 1
#elif defined(__FreeBSD__)
    #define PLATFORM_FREEBSD 1
#else
    #define PLATFORM_UNKNOWN 1
#endif

// 编译器检测
#if defined(_MSC_VER)
    #define COMPILER_MSVC 1
#elif defined(__clang__)
    #define COMPILER_CLANG 1
#elif defined(__GNUC__)
    #define COMPILER_GCC 1
#else
    #define COMPILER_UNKNOWN 1
#endif

// 架构检测
#if defined(_M_X64) || defined(__x86_64__)
    #define ARCH_X64 1
#elif defined(_M_IX86) || defined(__i386__)
    #define ARCH_X86 1
#elif defined(_M_ARM64) || defined(__aarch64__)
    #define ARCH_ARM64 1
#elif defined(_M_ARM) || defined(__arm__)
    #define ARCH_ARM 1
#else
    #define ARCH_UNKNOWN 1
#endif

// 导出宏
#if PLATFORM_WINDOWS
    #define EXPORT_API __declspec(dllexport)
    #define IMPORT_API __declspec(dllimport)
#else
    #define EXPORT_API __attribute__((visibility("default")))
    #define IMPORT_API
#endif

// 内联宏
#if COMPILER_MSVC
    #define FORCE_INLINE __forceinline
#else
    #define FORCE_INLINE inline __attribute__((always_inline))
#endif

// 调试宏
#if defined(DEBUG) || defined(_DEBUG)
    #define TP_DEBUG 1
#else
    #define TP_DEBUG 0
#endif 