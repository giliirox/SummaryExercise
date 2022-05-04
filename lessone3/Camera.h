#pragma once
#include "BaseMessage.h"
#include "StatusMessage.h"
#include "DiscoverMessage.h"
#include "Buffer.h"
#define NUMBER1 4

class Camera
{
	char id;
	BaseMessage** messages=nullptr;
	int numOfMessages = 0;
	int indexInArr = 0;
	Buffer* myBuffer;
	bool isActive;
public:
	Camera();
	Camera(char id,bool isActive);
	~Camera();
	void Generate();
	void SendToBuffer();
	void Run();
	void Stop();
	 char** GetBufferValue();
	int GetnumOfMessages();
	void SendToServer();

};

