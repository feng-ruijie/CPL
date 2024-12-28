你遇到的错误是因为 CMake 检测到之前使用了不同的生成器（`NMake Makefiles`），而你现在尝试使用 `MinGW Makefiles`。CMake 不允许在同一构建目录中混合使用不同的生成器。

### 解决方案

#### 1. **清理构建目录**

最简单的方法是删除现有的构建目录，重新创建一个新的构建目录并重新配置 CMake。

```sh
cd d:\programming\codes\12-link
rm -rf build  # 如果在 Windows 上使用 PowerShell 或 cmd，可以使用 rmdir /S /Q build
mkdir build
cd build
```

#### 2. **选择合适的生成器**

根据你使用的编译器选择合适的生成器：

- **MinGW-w64**：使用 `MinGW Makefiles`
- **Visual Studio**：使用 `Visual Studio` 生成器

##### 使用 MinGW-w64

```sh
cmake .. -G "MinGW Makefiles"
cmake --build .
```

##### 使用 Visual Studio

确保你已经安装了 Visual Studio，并通过开发者命令提示符运行以下命令：

```sh
cmake .. -G "Visual Studio 16 2019"  # 根据你的 Visual Studio 版本调整
cmake --build . --config Release
```

#### 3. **完整的步骤**

以下是完整的步骤，假设你选择使用 MinGW-w64：

1. **删除旧的构建目录**：
   ```sh
   cd d:\programming\codes\12-link
   rmdir /S /Q build  # 在 Windows 上使用 cmd
   mkdir build
   cd build
   ```

2. **配置 CMake 使用 MinGW Makefiles**：
   ```sh
   cmake .. -G "MinGW Makefiles"
   ```

3. **编译项目**：
   ```sh
   cmake --build .
   ```

4. **运行可执行文件**：
   ```sh
   .\josephus.exe
   ```

5.完整的机制

mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
.\josephus.exe

### 注意事项

- **环境变量**：确保 MinGW-w64 的 `bin` 目录已添加到系统的 `PATH` 环境变量中。
- **CMakeLists.txt**：确保你的 `CMakeLists.txt` 文件正确配置了编译器和源文件路径。

如果你仍然遇到问题，请提供详细的错误信息，以便进一步诊断。