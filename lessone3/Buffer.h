#pragma once
#include "BaseMessage.h"
#include <stdio.h>
#include <stdlib.h>
class Buffer
{
	 char** buffer=nullptr;
	
public:
	int last =0;
	Buffer();
	~Buffer();
	void AddToBuffer( char* newMessage);
	 char** GetBuffer();
	void CleanBuffer();

};

