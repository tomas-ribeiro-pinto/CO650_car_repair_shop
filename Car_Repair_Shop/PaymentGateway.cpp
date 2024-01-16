#include "PaymentGateway.h"

class Data {

public:
	string plate;
};


PaymentGateway::PaymentGateway()
{
}

PaymentGateway::~PaymentGateway()
{
}

bool PaymentGateway::initialise()
{
	port = 55555;
	wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequested, &wsaData);

	// dll file missing error
	if (wsaerr != 0) {
		cout << "--## PAYMENT DECLINED/FAILED ##--" << endl;
		cout << "Error: Missing required file!" << endl;
		return 0;
	}
}

bool PaymentGateway::connectToGateway() {
	
	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// error at socket
	if (clientSocket == INVALID_SOCKET) {
		cout << "--## PAYMENT DECLINED/FAILED ##--" << endl;
		cout << "Error: socket: " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}

	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);

	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
		// connection error to server
		cout << "--## PAYMENT DECLINED/FAILED ##--" << endl;
		cout << "Error: Failed to connect." << endl;
		WSACleanup();
		return 0;
	}
	return 1;
}

bool PaymentGateway::payBill(Bill *bill) {
	if(connectToGateway()) {
		char cardNumber[17];
		char buffer[200];
		cout << "\n\n PAYMENT DETAILS:" << endl;
		cout << "#####################\n" << endl;
		cout << "Enter your credit card number (Insert 16 digits):\n" << endl;
		cin.getline(cardNumber, 17);
		bill->setCardNumber(cardNumber);
		cout << "Enter card expiry month:" << endl;
		cin.getline(buffer, 200);
		cout << "Enter card expiry year:" << endl;
		cin.getline(buffer,200);
		cout << "Enter card security code" << endl;
		cin.getline(buffer, 200);

		// confirm payment
		cout << "Pay bill? (y/n)" << endl;
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			cout << "Contacting Bank Provider...\n";
			for (int i = 0; i < 10; i++)
			{
				cout << "##";
				Sleep(800/(i+1));
			}
			cout << endl;
			Data data;
			data.plate = "dffsdfsd";
			Payment payment = Payment(bill->getPlate(), to_string(bill->getTotalCost()), bill->getCardNumber());
			//int byteCount = send(clientSocket, (char*)&payment, sizeof(Payment), 0);
			int byteCount = send(clientSocket, (char*)&data, sizeof(Data), 0);
			if (byteCount == SOCKET_ERROR) {
				cout << "--## PAYMENT DECLINED/FAILED ##--" << endl;
				cout << "Error:" << WSAGetLastError() << endl;
				return 0;
			}
		}
		else
		{
			cout << "--## PAYMENT DECLINED/FAILED ##--" << endl;
			return 0;
		}
	}

	system("pause");
	WSACleanup();
	return 1;
}