
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

void Buffer :: AddToBuffer( char * newMessage)
{
       buffer = ( char**)realloc(buffer,sizeof(  char*)*++last);
	   buffer[last-1]= ( char*)malloc(strlen((char*)newMessage));
	   strcpy((char*)buffer[last - 1], (char*)newMessage);
}

 char ** Buffer::GetBuffer()
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
