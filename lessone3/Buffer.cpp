
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
	   buffer[last-1]= (unsigned char*)malloc(strlen((char*)newMessage));
	   strcpy((char*)buffer[last - 1], (char*)newMessage);
}

unsigned char ** Buffer::GetBuffer()
{
	return buffer;
}

void Buffer::CleanBuffer()
{
    int	i = 0;
	while (buffer&&buffer[i]!=NULL) {
	  free(buffer[i]);
	  i++;
	}
	free(buffer);
	buffer = NULL;
	
}
