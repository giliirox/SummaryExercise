#include "pch.h"
#include "Simulator.h"


Simulator::Simulator()
{
}


Simulator::~Simulator()
{
}

StatusMessage * Simulator::createStatusMessage()
{
		static int id = 0;
		id++;
		return new StatusMessage(id, 1, rand() % 3 + 1);
}



DiscoverMessage * Simulator::createDetectionMessage()
{
	static int id = 100;
	id++;
	return new DiscoverMessage(id, 2, rand() % 950000 + 500, rand() % 361, rand() % 1001);
}

void Simulator::generateAndSendMessage()
{
	std::cout << "befor:\n";
	for (int i = 0; i < 10; i++)
	{
		rand() % 2 + 1 == 1 ? buffer[i]= createStatusMessage() : buffer[i] = createDetectionMessage();
		buffer[i]->print();
	}
	std::cout << "after:\n";
	for (int i = 0; i < 10; i++)
	{
		buffer[i]->parseBack();
		buffer[i]->parseMessage();
		buffer[i]->print();
		
	}
	
}


