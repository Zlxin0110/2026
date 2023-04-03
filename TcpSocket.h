#ifndef _TCPSOCKET_H
#define _TCPSOCKET_H

#include <WinSock2.h>
#include <stdio.h>
//#include <iostream>
//using namespace std;

#define ErrMsg(msg) printf("[line:%d] %s failed code %d",__LINE__, msg, WSAGetLastError())

#pragma comment(lib,"ws2_32.lib")

// init network
bool init_network();
// close network
bool close_network();
// create socket
SOCKET create_server_socket();
// create client
SOCKET create_client_socket();
#endif

