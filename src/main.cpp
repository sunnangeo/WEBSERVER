#include <unistd.h>

#include "../include/webserver.h"

int main(int argc, char **argv) {
  /* 守护进程 后台运行 */
  // daemon(1, 0);

  int port = atoi(argv[1]);

  std::cout << "sunnan" << std::endl;
  WebServer server(
      port, 3, 60000, false, /* 端口 ET模式 timeoutMs 优雅退出  */
      3306, "root", "396243066_wsnnG", "webserver", /* Mysql配置 */
      12, 3, true, 1,
      1024); /* 连接池数量 线程池数量 日志开关 日志等级 日志异步队列容量 */

  // 启动服务器
  server.Start();
}
