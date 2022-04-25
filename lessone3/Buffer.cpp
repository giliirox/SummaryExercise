#include "pch.h"
#include "Buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Buffer::Buffer()
{
}


Buffer::~Buffer()
{
}

void Buffer::AddToBuffer(unsigned char * newMessage)
{
	
	if (buffer == nullptr)
	{
		buffer = (unsigned char**)malloc(sizeof(char*));
	}
	else
	{
	realloc(buffer,sizeof(buffer)+ sizeof(char*));
	}
	last++;
	buffer[last]=newMessage;
	
}

unsigned char ** Buffer::GetBuffer()
{
	return buffer;
}

void Buffer::CleanBuffer()
{
    int	i = 0;
	while (buffer[i]) {
	  free(buffer[i]);
	  i++;
	}
	free(buffer);
	
}
