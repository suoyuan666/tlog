#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <tlog.h>

#include <chrono>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <ios>
#include <memory>
#include <string>
#include <string_view>

namespace tlog {

auto tprint(std::initializer_list<std::string_view>&& src, tlog_status status,
            const std::pair<bool, std::string_view>& wf) -> void {
  static const std::string INFO_PREFIX = "[INFO]";
  // rgb(0, 255, 255): blue
  static const std::string DEBUG_PREFIX =
      fmt::format(fg(fmt::rgb(0, 255, 255)), "[DEBUG]");
  // rgb(255, 255, 0): yellow
  static const std::string WARNNING_PREFIX =
      fmt::format(fg(fmt::rgb(255, 255, 0)), "[WARNNING]");
  // rgb(255, 0, 0): red
  static const std::string ERROR_PREFIX =
      fmt::format(fg(fmt::rgb(255, 0, 0)), "[ERROR]");
  // rgb(0, 255, 0): green
  static const std::string SUCCESS_PREFIX =
      fmt::format(fg(fmt::rgb(0, 255, 0)), "[SUCCESS]");

  if (src.size() == 0) {
    return;
  }

  const auto now_time = std::chrono::system_clock::now();
  if (src.size() == 0) {
    return;
  }
  std::shared_ptr<std::string> prefix;
  std::string val{};

  for (auto str : src) {
    val += str;
  }

  switch (status) {
    case INFO:
      prefix = std::make_shared<std::string>(INFO_PREFIX);
      break;
    case DEBUG:
      prefix = std::make_shared<std::string>(DEBUG_PREFIX);
      break;
    case WARNNING:
      prefix = std::make_shared<std::string>(WARNNING_PREFIX);
      break;
    case ERROR:
      prefix = std::make_shared<std::string>(ERROR_PREFIX);
      break;
    case SUCCESS:
      prefix = std::make_shared<std::string>(SUCCESS_PREFIX);
      break;
  }

  auto t_c = std::chrono::system_clock::to_time_t(now_time);
  const std::string message = fmt::format("{} {:%Y-%m-%d %H:%M:%S}: {}\n",
                                          *prefix, fmt::localtime(t_c), val);

  if (status == tlog_status::ERROR || status == tlog_status::WARNNING) {
    fmt::print(stderr, "{}", message);
  } else {
    fmt::print(stdout, "{}", message);
  }

  if (!wf.first) {
    return;
  }

  std::string path;
  if (wf.second.empty()) {
    path = "/tmp/tlog.log";
  } else {
    path = wf.second;
  }

  std::ofstream wfile{path, std::ios::binary | std::ios::app};
  fmt::print(wfile, "{}", message);
}
}  // namespace tlog
