#include "pch.h"
#include "MainSimulator.h"


MainSimulator::MainSimulator()
{
	CamerasArr =(Camera**) malloc(sizeof(Camera*)*N);
	for (int i = 0; i < N; i++)
	{
		CamerasArr[i] = new Camera(char(i+'a'),true);
	}
	RunAllCameras();
}


MainSimulator::~MainSimulator()
{
}

void MainSimulator::RunAllCameras()
{
	char c;
	std::thread* myThreads=(std::thread*)malloc(sizeof(std::thread)*N);

	for (int i = 0; i <N ; i++)
	{
		myThreads[i] = std::thread(&Camera::Run,i);
	}
	std::cin >> c;
	for (int i = 0; i < N; i++)
	{
		CamerasArr[i]->Stop();
	}
}
