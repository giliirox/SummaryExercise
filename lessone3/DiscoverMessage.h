#pragma once
#include "BaseMessage.h"
class DiscoverMessage :
	public BaseMessage
{
private:

	float distance;//500-1000
    float angle;//0-360
    float speed;//0-1000

public:
	DiscoverMessage();
	DiscoverMessage(int messageId, int messageType, float distance, float angle, float speed);
	
	~DiscoverMessage();

    void  parseMessage();
	void parseBack();
	void print();
};

