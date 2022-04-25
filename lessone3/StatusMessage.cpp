#include "pch.h"
#include "StatusMessage.h"
#include <stdio.h>
#include  <cstring>
#include <stdlib.h>
#include <iostream>


void StatusMessage::parseMessage()
{
	if (!this->messageBuffer)
	{
		return;
	}
   std::memcpy(&(this->messageType), this->messageBuffer,2);
   std::memcpy(&(this->status), this->messageBuffer + 2, 1);
}

void StatusMessage::parseBack()
{
	this->messageBuffer =(unsigned char*) malloc(sizeof(char) * 3);
	std::memcpy(this->messageBuffer, &(this->messageType), 2);
	std::memcpy(this->messageBuffer + 2, &(this->status), 1);
}

void StatusMessage::print()
{
	std::cout << "type: " << this->messageType << "\nstatus: " << this->status<<"\n";
}

StatusMessage::StatusMessage()
{
	
}

StatusMessage::StatusMessage(int messageId, int messageType, short status):BaseMessage(messageId, messageType)
{
	
	if (status > 3 || status < 1)
		this->status = 0;
  
	else
		this->status = status;
}


StatusMessage::~StatusMessage()
{
}

