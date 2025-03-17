# Template Project

这是一个跨平台的 C++ 项目模板。

## 项目结构

```
templateproject/
├── src/          # 源代码
├── include/      # 头文件
├── tests/        # 测试文件
├── build/        # 构建目录
└── docs/         # 文档
```

## 依赖项

项目使用 vcpkg 管理依赖，主要依赖包括：
- fmt: 现代化的格式化库
- spdlog: 快速的日志库
- nlohmann-json: JSON 处理库
- GTest: Google 测试框架

## 构建要求

- CMake 3.15 或更高版本
- C++17 兼容的编译器
- Git
- vcpkg

## 构建步骤

1. 安装依赖：
```bash
vcpkg install
```

2. 构建项目：
```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake
make
```

3. 运行测试：
```bash
ctest
```

## 许可证

MIT License 