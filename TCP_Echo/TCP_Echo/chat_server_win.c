//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <winsock2.h>
//
//#pragma comment(lib, "ws2_32.lib")
//#define BUF_SIZE 1024
//void ErrorHandling(const char * message);
//
//int main(int argc, char *argv[]) {
//	WSADATA  wsaData;
//	SOCKET hServSock, hClntSock;
//	SOCKADDR_IN servAdr, clntAdr;
//	int clntAdrSize;
//
//	char message[BUF_SIZE];
//	int strLen;
//
//	DWORD size = sizeof(clntAdr);
//	char strAddrBuf[20];
//	clntAdrSize = sizeof(clntAdr);
//
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//		ErrorHandling("WSAStartup() error!");
//
//	hServSock = socket(PF_INET, SOCK_STREAM, 0);
//	if (hServSock == INVALID_SOCKET)
//		ErrorHandling("socket() error");
//
//	memset(&servAdr, 0, sizeof(servAdr));
//	servAdr.sin_family = AF_INET;
//	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
//	servAdr.sin_port = htons(5000);
//
//	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
//		ErrorHandling("bind() error");
//
//	if (listen(hServSock, SOMAXCONN) == SOCKET_ERROR)
//		ErrorHandling("listen() error");
//
//	for (int i = 0; i < 5; i++) {
//		hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSize);
//		if (hClntSock == INVALID_SOCKET)
//			ErrorHandling("accept() error");
//
//
//		WSAAddressToString((SOCKADDR*)&clntAdr, sizeof(clntAdr), NULL, strAddrBuf, &size);
//		printf("%s\n", strAddrBuf);
//
//		while ((strLen = recv(hClntSock, message, BUF_SIZE, 0)) != 0) {
//			printf("Message from clnt : %s\n", message);
//			printf("send Message : ");
//			fgets(message, BUF_SIZE, stdin);
//			send(hClntSock, message, BUF_SIZE - 1, 0);
//		}
//
//		closesocket(hClntSock);
//	}
//	closesocket(hServSock);
//	WSACleanup();
//	return 0;
//}
//
//void ErrorHandling(const char* message) {
//	fputs(message, stderr);
//	fputc('\n', stderr);
//	exit(1);
//}