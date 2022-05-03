#pragma once
#include "Camera.h"
#include <thread>
#include <iostream>
#include <stdlib.h>

#define NUMBER1 4
class MainSimulator
{
	Camera* CamerasArr[NUMBER1];
public:
	MainSimulator();
	~MainSimulator();
	void RunAllCameras();
	void PrintDataFromAllCameras();
};

