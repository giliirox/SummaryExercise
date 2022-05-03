#pragma once
#include "BaseMessage.h"
#include <stdio.h>
#include <stdlib.h>
class Buffer
{
	unsigned char** buffer=nullptr;
	
public:
	int last =0;
	Buffer();
	~Buffer();
	void AddToBuffer(unsigned char* newMessage);
	unsigned char** GetBuffer();
	void CleanBuffer();

};

