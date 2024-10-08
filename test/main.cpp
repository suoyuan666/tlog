#include <tlog.h>

#include <string>

int main(void) {
  std::string aaa = "abd";
  // clang-format off
  tlog::tprint({"test", "测试", aaa}, tlog::tlog_status::INFO, tlog::NO_LOG_FILE);
  tlog::tprint({}, tlog::tlog_status::INFO, tlog::NO_LOG_FILE);
  tlog::tprint({"test", "测试", aaa}, tlog::tlog_status::SUCCESS, tlog::NO_LOG_FILE);
  tlog::tprint({"test", "测试"}, tlog::tlog_status::DEBUG, tlog::NO_LOG_FILE);
  tlog::tprint({"test", "测试"}, tlog::tlog_status::WARNNING, tlog::NO_LOG_FILE);
  tlog::tprint({"test", "测试"}, tlog::tlog_status::ERROR, tlog::NO_LOG_FILE);
  return 0;
}
