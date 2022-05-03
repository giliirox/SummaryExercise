#include "pch.h"
#include "MainSimulator.h"


MainSimulator::MainSimulator()
{

	for (int i = 0; i < NUMBER1; i++)
	{
		CamerasArr[i] = new Camera(char(i+'a'),true);
	}

}


MainSimulator::~MainSimulator()
{
}

void MainSimulator::RunAllCameras()
{
	char c;
	std::thread myThreads[NUMBER1];
	std::thread SendToServerThreads[NUMBER1];
	

	for (int i = 0; i <NUMBER1 ; i++)
	{
		myThreads[i] = std::thread(&Camera::Run,(*(CamerasArr[i]) ));
		SendToServerThreads[i] = std::thread(&Camera::SendToServer,*(CamerasArr[i]));
	}

	std::cin >> c;

	for (int i = 0; i < NUMBER1; i++)
	{
		CamerasArr[i]->Stop();
		myThreads[i].detach();
	}

	
}

void MainSimulator::PrintDataFromAllCameras()
{
	for (int i = 0; i < NUMBER1; i++)
	{
		unsigned char** result = CamerasArr[i]->GetBufferValue();
		int numOfMessages = CamerasArr[i]->GetnumOfMessages();
		std::cout << std::endl;
		std::cout << "camera number:" << i + 1 << std::endl;
		for (int j = 0; j < 2; j++)
		{
          std::cout <<j+1<<": "<< result[i]<< std::endl;
		}
			
		
	}
}
