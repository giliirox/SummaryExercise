#pragma once
#include "Camera.h"
#include <thread>
#include <iostream>
#include <stdlib.h>

#define N 4
class MainSimulator
{
	Camera** CamerasArr;
public:
	MainSimulator();
	~MainSimulator();
	void RunAllCameras();
	void PrintDataFromAllCameras();
};

