#include "TcpSocket.h"

#define PORT 8888
/// <summary>
/// inti network
/// </summary>
/// <returns></returns>
bool init_network()
{
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2),&wsadata)) {
		ErrMsg("init_socket");
		return false;
	}
	return true;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool close_network()
{
	if (0 != WSACleanup()) {
		ErrMsg("close_socket");
		return false;
	}

	return true;
}

/// @brief create server socket 
/// @return 
SOCKET create_server_socket()
{
	// type:SOCK_STREAM / protocol:IPPROTO_TCP
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET) {
		ErrMsg("create_server_socket-socket");
		return INVALID_SOCKET;
	}

	// Internet style
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = PORT;
	addr.sin_addr.S_un.S_addr = ADDR_ANY;// inet_addr("127.0..0.1")
	
	// bind
	if (SOCKET_ERROR == bind(fd,(SOCKADDR*)&addr, sizeof(addr))) {
		ErrMsg("create_server_socket-bind");
		return SOCKET_ERROR;
	}

	// listen(fd:socket / 10: listen count)
	listen(fd, 10);

	return fd;
}

/// @brief create client socket
/// @return 
SOCKET create_client_socket()
{
	// type:SOCK_STREAM / protocol:IPPROTO_TCP
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET) {
		ErrMsg("create_client_socket -- socket");
		return INVALID_SOCKET;
	}

	// Internet style
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = PORT;
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	
	if (connect(fd, (SOCKADDR*)&addr, sizeof(addr))== SOCKET_ERROR) {
		ErrMsg("create_client_socket -- connect");
		return -1;
	}


	return fd;
}
