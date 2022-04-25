#include "pch.h"
#include "DiscoverMessage.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


DiscoverMessage::DiscoverMessage()
{
}

DiscoverMessage::DiscoverMessage(int messageId, int messageType, float distance, float angle, float speed):BaseMessage(messageId,messageType)
{
	if (distance >= 500 && distance <= 10000)
		this->distance = distance;
	else
		this->distance = 0;
	if (speed >= 0 && speed <= 1000)
		this->speed = speed;
	else
		this->speed = speed;
	if (angle >= 0 && angle <= 360)
		this->angle = angle;
	else
		this->angle = 0;
}


DiscoverMessage::~DiscoverMessage()
{
}

void DiscoverMessage::parseMessage()
{

	if (!this->messageBuffer)
	{
		return;
	}
	std::memcpy(&(this->messageType), this->messageBuffer, 2);
	std::memcpy(&(this->distance), this->messageBuffer + 2, 4);
	std::memcpy(&(this->angle), this->messageBuffer + 6, 4);
	std::memcpy(&(this->speed), this->messageBuffer +10, 4);
}

void DiscoverMessage::parseBack()
{

	this->messageBuffer = (unsigned char*)malloc(sizeof(char) * 14);
	std::memcpy( this->messageBuffer, &(this->messageType), 2);
	std::memcpy(this->messageBuffer + 2, &(this->distance), 4);
	std::memcpy(this->messageBuffer + 6, &(this->angle), 4);
	std::memcpy( this->messageBuffer + 10, &(this->speed), 4);

}

void DiscoverMessage::print()
{

	std::cout << "type: " << this->messageType << "\ndistance: " << this->distance<<"\nspeed: "<<this->speed<<"\nangle: "<<this->angle<<"\n";
}
