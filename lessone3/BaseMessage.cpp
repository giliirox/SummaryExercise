#include "pch.h"
#include "BaseMessage.h"


BaseMessage::BaseMessage()
{
}

BaseMessage::BaseMessage(int messageId, int messageType)
{
	this->messageId = messageId;
	this->messageType = messageType;
}


BaseMessage::~BaseMessage()
{
}

 char* BaseMessage::getMessageBuffer()
{
	return this->messageBuffer;
}


