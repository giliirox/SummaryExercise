#pragma once
#include "BaseMessage.h";
#include <iostream>
#include <stdlib.h>
#include "DiscoverMessage.h"
#include "StatusMessage.h"
#define NUM 10

class Simulator
{
	BaseMessage* buffer[NUM];
public:
	Simulator();
	~Simulator();
	StatusMessage* createStatusMessage();
	
	
	DiscoverMessage* createDetectionMessage();
	void generateAndSendMessage();
};






