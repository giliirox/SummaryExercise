#pragma once
#include "BaseMessage.h"
#include <stdio.h>
#include <stdlib.h>
class Buffer
{
	unsigned char** buffer=NULL;
	int last =0;
public:
	Buffer();
	~Buffer();
	void AddToBuffer(unsigned char* newMessage);
	unsigned char** GetBuffer();
	void CleanBuffer();

};

