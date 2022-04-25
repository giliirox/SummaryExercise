#pragma once
#include "BaseMessage.h"
#include "StatusMessage.h"
#include "DiscoverMessage.h"
#include "Buffer.h"
#define N 4

class Camera
{
	char id;
	BaseMessage** messages=nullptr;
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

};

