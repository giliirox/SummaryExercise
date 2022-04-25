#pragma once
#include "BaseMessage.h"
class StatusMessage :public BaseMessage

{

private:
	short status;//1-3
public:
	 void  parseMessage();
	 void parseBack();
	 void print();

	
	StatusMessage();
	StatusMessage(int messageId, int messageType, short status);
	
	~StatusMessage();
};

