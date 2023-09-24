#include <iostream>
#include <thread> //多线程

#pragma comment (lib,"ws2_32.lib") //加载socket

using namespace std;

void Send(SOCKET client, char send_buf[]);
void Recv(SOCKET client, char recv_buf[]);

int main()
{
    int len;

    char send_buf[100];//发送缓冲区
    char recv_buf[100];//接收缓冲区

    thread thread_send;
    thread thread_recv;

    SOCKET server;
    SOCKET client;

    SOCKADDR_IN server_addr;//使用结构体 SOCKADDR_IN 存储配置
    SOCKADDR_IN client_addr;

    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    server = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server_addr, 0, sizeof(server_addr)); //清零
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //server端ip地址
    server_addr.sin_port = htons(1234); //监听端口
    bind(server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR));

    listen(server, 10);
    cout << "等待连接......" << endl;

    len = sizeof(SOCKADDR);
    client = accept(server, (SOCKADDR*)&client_addr, &len);
    cout << "连接成功" << endl;

    thread_send = thread(Send, client, send_buf);
    thread_recv = thread(Recv, client, recv_buf);

    thread_send.join();
    thread_recv.join();

    //关闭套接字
    closesocket(server);
    closesocket(client);

    WSACleanup();
    return 0;
}

void Send(SOCKET client, char send_buf[]) {
    while (true) {
        cin >> send_buf;
        send(client, send_buf, 100, 0);
    }
}

void Recv(SOCKET client, char recv_buf[]) {
    while (true) {
        recv(client, recv_buf, 100, 0);
        cout << recv_buf << endl;
    }
}
