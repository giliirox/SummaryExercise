#include "pch.h"
#include "Camera.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <sstream>

#include <WinSock2.h>
#include <WS2tcpip.h>


using namespace std;



Camera::Camera()
{
	
}

Camera::Camera(char id, bool isActive)
{
	this->id = id;
	this->isActive = isActive;
	this->myBuffer = new Buffer();

}


Camera::~Camera()
{
	free(myBuffer);
	free(messages);
}


StatusMessage * createStatusMessage()
{
	static int id = 0;
	id++;
	return new StatusMessage(id, 1, rand() % 3 + 1);
}

DiscoverMessage * createDetectionMessage()
{
	static int id = 100;
	id++;
	return new DiscoverMessage(id, 2, rand() % 950000 + 500, rand() % 361, rand() % 1001);
}

void Camera::Generate()
{
	int numOfMessagesToDo = rand() % 10 + 1;
	
	for (int i = 0; i < numOfMessagesToDo; i++)
	{
			messages= (BaseMessage**)realloc(messages, sizeof(BaseMessage*)*(indexInArr + 1));
		rand() % 2 + 1 == 1 ? messages[indexInArr++] = (BaseMessage*)createStatusMessage() : messages[indexInArr++] = createDetectionMessage();
	}
}

void Camera::SendToBuffer()
{
	int h = indexInArr;
	for (int i = 0; i < h; i++)
	{	
		messages[i]->parseBack();
		myBuffer->AddToBuffer(messages[i]->getMessageBuffer());
		free(messages[i]);
	}
	free(messages);
	messages = NULL;
	numOfMessages += indexInArr;
	indexInArr = 0;
}

void Camera::Run()
{
	while (isActive) {
		Generate();
		
		SendToBuffer();
		
	}
}

void Camera::Stop()
{
	isActive = false;
}

unsigned char ** Camera::GetBufferValue()
{
	return myBuffer->GetBuffer();
}

int Camera::GetnumOfMessages()
{
	return numOfMessages;
}

void Camera::SendToServer()
{
	while(isActive){
		Sleep(3000);
		cout << "trying to connect" << endl;
		WSAData wsaData;
		WORD DllVersion = MAKEWORD(2, 1);
		if (WSAStartup(DllVersion, &wsaData) != 0) {
			cout << "Winsock Connection Failed!" << endl;
			exit(1);
		}
		string getInput;
		SOCKADDR_IN addr;
		int addrLen = sizeof(addr);
		IN_ADDR ipvalue;
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		addr.sin_port = htons(8080);
		addr.sin_family = AF_INET;

		SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
		if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
			cout << "Connected!" << endl;

			for (int i = 0; i < 2; i++)
			{
				getInput = (char*)myBuffer->GetBuffer()[i];
				send(connection, getInput.c_str(), getInput.length(), 0);
			}
		

		}
		else {
			cout << "Error Connecting to Host" << endl;
			exit(1);
		}
		myBuffer->CleanBuffer();
		
       }
return;
	}

