#pragma once
class BaseMessage
{
      protected:
		  unsigned char* messageBuffer;
		  int messageId;
		  int messageType;

public:
	BaseMessage();
	BaseMessage(int messageId,int messageType);
	
	
	~BaseMessage();
	virtual void  parseMessage() = 0;
	virtual void parseBack() = 0;
	virtual void print() = 0;

	unsigned char* getMessageBuffer();

};

