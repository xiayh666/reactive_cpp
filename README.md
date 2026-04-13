# Reactive (C++ Learning Project)

一个用于学习与实验的 C++ 响应式框架原型项目。

项目目标：逐步实现一个**高性能、可扩展、易调试**的 C++ 响应式框架，并在实现过程中沉淀设计与性能优化经验。
项目教程：[](https://lumia431.github.io/)

## 项目状态


- `Resource<T>`：基础数据容器（可读写）
- `Expression<F, Args...>`：表达式封装，支持延迟计算（`evaluate()`）
- `reactive::var(...)`：创建响应式变量
- `reactive::calc(...)`：创建计算表达式
- `xmake` 构建
- `clangd` 所需 `compile_commands.json` 支持

## 快速开始

### 1. 构建

```bash
xmake
```

### 2. 运行

```bash
xmake run reactive
```

### 3. 生成 clangd 编译数据库

```bash
xmake project -k compile_commands
```

项目根目录已包含 `.clangd`，会读取根目录下的 `compile_commands.json`。

## 当前 API 示例

```cpp
#include <data_source.hpp>
#include <iostream>

int main() {
    auto a = reactive::var("hello reactive");
    std::cout << a.get_value() << std::endl;

    a.set_value("after");
    std::cout << a.get_value() << std::endl;

    auto b = reactive::calc([](int x, int y) { return x + y; }, 10, 25);
    b.evaluate();
    std::cout << b.get_value() << std::endl;
}
```

## 项目结构

```text
.
├── include/
│   ├── resource.hpp      # 基础数据容器
│   ├── expression.hpp    # 计算表达式
│   └── data_source.hpp   # 对外 API（var/calc）
├── src/
│   └── main.cpp          # 示例入口
└── xmake.lua             # 构建配置
```

## 设计方向（Roadmap）

1. 依赖追踪图（DAG）
2. 自动脏标记与懒求值
3. 批量调度与拓扑更新
4. 订阅机制（watch/effect）
5. 内存与对象生命周期优化
6. 并发调度（无锁队列/分片调度）
7. 基准测试与性能剖析（benchmark + profiler）


## 后续计划建议

- 增加 `tests/` 与单元测试（建议 gtest）
- 建立 `bench/` 做性能基线
- 为表达式与依赖图补充错误处理与诊断信息
