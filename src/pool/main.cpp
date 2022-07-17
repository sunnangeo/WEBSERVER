
#include "../../include/mysqlconnection.h"
#include <iostream>

int main() {
    Connection conn;
    string sql = "INSERT INTO user(username, password) VALUES('jiawenchao','123456')";
    conn.connect("localhost", 3306, "root", "396243066_wsnnG", "webserver");
    conn.update(sql);
    return 0;
}