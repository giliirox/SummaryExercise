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

void Buffer :: AddToBuffer(unsigned char * newMessage)
{
       buffer = (unsigned char**)realloc(buffer,sizeof( unsigned char*)*++last);
	   buffer[last-1]=newMessage;
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
