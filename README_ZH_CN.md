[![GPL v2 license](https://img.shields.io/badge/license-GPL_2-blue.svg)](https://raw.githubusercontent.com/suoyuan666/tlog/master/LICENSE)
[![English](https://wangchujiang.com/sb/lang/english.svg)](README.md)

## 介绍

tlog 是一个用于在终端中输出 RGB 颜色的 log 信息的 C++ 库。

C++ 标准: C++ 17

## 使用方法

在 CMakeLists.txt 中添加该目录，并且使用 `target_link_libraries()` 链接 `tlog`。

可以参考 test 目录下的测试程序源文件

```cpp
#include <tlog.h>

auto main() -> int {
    tlog::tprint({"test", "测试"}, tlog::tlog_status::INFO, tlog::NO_LOG_FILE);
    tlog::tprint({"test", "测试"}, tlog::tlog_status::DEBUG, tlog::NO_LOG_FILE);
    tlog::tprint({"test", "测试"}, tlog::tlog_status::ERROR, tlog::NO_LOG_FILE);
    tlog::tprint({"test", "测试"}, tlog::tlog_status::SUCCESS, tlog::NO_LOG_FILE);
    tlog::tprint({"test", "测试"}, tlog::tlog_status::WARNNING, tlog::NO_LOG_FILE);
    return 0;
}
```

`tlog::tprint()` 的第一个参数是要输出的值，这是一个 `std::initializer_list<std::string_view>` 类，第二个参数是该消息的级别，tlog 提供了五个级别: `SUCCESS`, `INFO`, `DEBUG`, `WARNNING` 和 `ERROR`，第三个参数用于表示该log信息保存的日志文件内容，默认提供了两个: `tlog::NO_LOG_FILE` 和 `tlog::DEFAULT_LOG_FILE`，前者设置不产生日志文件，后者是一个默认的日志文件路径 **/tmp/tlog.log**。

效果图:

![tprint demo](assets/img/tlog_tprint_demo.png)