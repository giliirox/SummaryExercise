#include "pch.h"
#include "Camera.h"

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
	int numOfMessages = rand() % 5 + 1;
	for (int i = 0; i < numOfMessages; i++)
	{
		if (!messages)
		{
			messages = (BaseMessage**)malloc(sizeof(BaseMessage*));
		}
		else {
			realloc(messages, sizeof(BaseMessage*)*indexInArr + 2);
			indexInArr++;
		}
		rand() % 2 + 1 == 1 ? messages[indexInArr] = (BaseMessage*)createStatusMessage() : messages[indexInArr] = createDetectionMessage();
	}
}

void Camera::SendToBuffer()
{
	for (int i = 0; i < indexInArr+1; i++)
	{	
		messages[i]->parseBack();
		myBuffer->AddToBuffer(messages[i]->getMessageBuffer());
		free(messages[i]);
	}
	free(messages);
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
