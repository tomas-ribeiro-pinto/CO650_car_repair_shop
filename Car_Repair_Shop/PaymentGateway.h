#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <tchar.h>
#include "iostream"
#include "Bill.h"
#include "Payment.h"

using namespace std;

class PaymentGateway
{
private:
	SOCKET clientSocket;
	int port;
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequested;
	sockaddr_in clientService;

public:
	PaymentGateway();
	~PaymentGateway();
	bool initialise();
	bool connectToGateway();
	bool payBill(Bill *bill);
};

