#include "pch.h"
#include "MainSimulator.h"


MainSimulator::MainSimulator()
{
	CamerasArr =(Camera**) malloc(sizeof(Camera*)*N);
	for (int i = 0; i < N; i++)
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
	std::thread myThreads[N];
	//std::thread* myThreads=(std::thread*)malloc(sizeof(std::thread)*N);

	for (int i = 0; i <N ; i++)
	{
		myThreads[i] = std::thread(&Camera::Run,(*(CamerasArr[i]) ));
	}
	std::cin >> c;

	for (int i = 0; i < N; i++)
	{
		CamerasArr[i]->Stop();
		myThreads[i].detach();
	}

	
}

void MainSimulator::PrintDataFromAllCameras()
{
	for (int i = 0; i < N; i++)
	{
		unsigned char** result = CamerasArr[i]->GetBufferValue();
		int numOfMessages = CamerasArr[i]->GetnumOfMessages();
		std::cout << std::endl;
		std::cout << "camera number:" << i + 1 << std::endl;
		for (int j = 0; j < 2; j++)
		{
          std::cout <<j+1<<": "<< (int)result[i]<< std::endl;
		}
			
		
	}
}
