#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>
#include "iostream"
#include "Payment.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	SOCKADDR_STORAGE from;
	int retval, fromlen;
	char servstr[NI_MAXSERV], hoststr[NI_MAXHOST];
	SOCKET serverSocket, clientSocket;
	int port = 55555;
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequested, &wsaData);
	if (wsaerr != 0) {
		cout << "The Winsock dll not found!" << endl;
		return 0;
	}
	else {
		cout << "The Winsock dll found!" << endl;
		cout << "The status: " << wsaData.szSystemStatus << endl;
	}

	serverSocket = INVALID_SOCKET;
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET) {
		cout << "Error at socket(): " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}
	else {
		cout << "socket() is OK!" << endl;
	}

	sockaddr_in service;
	service.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
	service.sin_port = htons(port);
	if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {
		cout << "bind() failed: " << WSAGetLastError() << endl;
		closesocket(serverSocket);
		WSACleanup();
		return 0;
	}
	else {
		cout << "bind() is OK!" << endl;
	}

	while (true)
	{
		if (listen(serverSocket, 1) == SOCKET_ERROR)
			cout << "listen(): Error listening on socket " << WSAGetLastError() << endl;
		else
			cout << "listen() is OK, I'm waiting for connections..." << endl;

		fromlen = sizeof(from);
		clientSocket = accept(serverSocket, (SOCKADDR*)&from, &fromlen);

		if (clientSocket == INVALID_SOCKET) {
			cout << "accept failed: " << WSAGetLastError() << endl;
			WSACleanup();
			return -1;
		}
		cout << "Accepted connection" << endl;
		retval = getnameinfo((SOCKADDR*)&from,
			fromlen,
			hoststr,
			NI_MAXHOST,
			servstr,
			NI_MAXSERV,
			NI_NUMERICHOST | NI_NUMERICSERV);
		if (retval != 0) {
			cout << "getnameinfo failed: " << retval << endl;
			WSACleanup();
			return -1;
		}

		cout << "Accepted connection from host " << hoststr << " and port " << servstr << endl;

		Payment payment = Payment();
		int byteCount = recv(clientSocket, (char*)&payment, sizeof(Payment), 0);
		if (byteCount < 0) {
			printf("Client: error %ld.\n", WSAGetLastError());
			return 0;
		}
		else {
			cout << "Payment Received!" << endl;
			payment.displayBill();


			char buffer[2] = "1";
			int byteCountSnd = send(clientSocket, buffer, 2, 0);
			if (byteCountSnd == SOCKET_ERROR) {
				cout << "--## PAYMENT DECLINED/FAILED ##--" << endl;
				cout << "Error:" << WSAGetLastError() << endl;
				return 0;
			}
		}

		closesocket(serverSocket);
		closesocket(clientSocket);

		system("pause");
		WSACleanup();
	}


	return 0;
}
