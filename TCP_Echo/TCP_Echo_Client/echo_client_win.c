#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")
#define BUF_SIZE 1024
void ErrorHandling(const char * message);

int main(int argc, char *argv[]) {
	WSADATA  wsaData;
	SOCKET hSock;
	char message[BUF_SIZE];

	SOCKADDR_IN servAdr;
	int strlen;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error!");

	hSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAdr.sin_port = htons(5000);

	if (connect(hSock, (SOCKADDR*)&servAdr, sizeof(servAdr))==SOCKET_ERROR)
		ErrorHandling("connect() error");

	while (1) {
		fputs("input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);

		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;

		send(hSock, message, sizeof(message), 0);
		strlen = recv(hSock, message, BUF_SIZE - 1, 0);
		message[strlen] = 0;
		printf("Message from server : %s\n", message);
	}

	closesocket(hSock);
	WSACleanup();
	return 0;
}

void ErrorHandling(const char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}