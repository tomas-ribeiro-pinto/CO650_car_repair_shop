#include "PaymentGateway.h"

PaymentGateway::PaymentGateway()
{
}

PaymentGateway::~PaymentGateway()
{
}

// OBJECTIVE 12 - WINSOCK CLIENT
// Initialises Payment Gateway by setting a socket connection with server
bool PaymentGateway::initialise()
{
	// port number used for listening by the server
	port = 55555;
	wVersionRequested = MAKEWORD(2, 2);
	// initialise DLL
	wsaerr = WSAStartup(wVersionRequested, &wsaData);

	// DLL file missing error
	if (wsaerr != 0) {
		// OBJECTIVE 11 - EXCEPTION HANDLING
		// throws payment exception
		PaymentException ex(0);
		try {
			throw ex;
		}
		catch (PaymentException& e)
		{
			cout << e.what() << endl;
			cout << "Error: Missing required file!" << endl;
		}
		return 0;
	}
}

bool PaymentGateway::connectToGateway() 
{
	// Create client socket 	
	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// error at socket
	if (clientSocket == INVALID_SOCKET) {
		PaymentException ex(0);
		try {
			throw ex;
		}
		catch (PaymentException& e)
		{
			cout << e.what() << endl;
			cout << "Error: socket: " << WSAGetLastError() << endl;
		}
		WSACleanup();
		return 0;
	}

	// connection details such as IP address
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);

	// trys connecting to server, throws payment exception if unsuccessful
	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
		// connection error to server
		PaymentException ex(0);
		try {
			throw ex;
		}
		catch (PaymentException& e)
		{
			cout << e.what() << endl;
			cout << "Error: Failed to connect." << endl;
		}
		WSACleanup();
		return 0;
	}
	return 1;
}

bool PaymentGateway::payBill(Bill *bill) 
{
	// if connection was made successfully
	// ask for payment details and send them to server
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

			// Create a Payment object and send it to the Server
			Payment payment = Payment(bill->getPlate(), bill->getTotalCost(), bill->getCardNumber());
			int byteCount = send(clientSocket, (char*)&payment, sizeof(Payment), 0);
			if (byteCount == SOCKET_ERROR) {
				PaymentException ex(bill->getTotalCost());
				try {
					throw ex;
				}
				catch (PaymentException& e)
				{
					cout << e.what() << " Total Bill: " << e.cost << endl;
					cout << "Error:" << WSAGetLastError() << endl;
				}
				return 0;
			}


			// Listen back for payment confirmation, on success returns true
			// If ther is a client error returns payment exception and total cost of payment
			char success[2];
			int byteCountRcv = recv(clientSocket, success, 2, 0);
			if (byteCountRcv < 0) {
				PaymentException ex(bill->getTotalCost());
				try {
					throw ex;
				}
				catch (PaymentException& e)
				{
					cout << e.what() << " Total Bill: " << e.cost << endl;
					printf("Client: error %ld.\n", WSAGetLastError());
				}
				return 0;
			}
			if (success[0] == 49) {
				return 1;
			}
		}
		else
		{
			PaymentException ex(0);
			try {
				throw ex;
			}
			catch (PaymentException& e)
			{
				cout << e.what() << endl;
			}
			return 0;
		}
	}

	WSACleanup();
	return 0;
}