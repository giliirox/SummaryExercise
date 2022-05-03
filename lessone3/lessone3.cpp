#define  _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <iostream>
#include "MainSimulator.h"
#pragma comment (lib, "Ws2_32.lib")
int main()
{
	MainSimulator* mySim = new MainSimulator();
	mySim->RunAllCameras();
	mySim->PrintDataFromAllCameras();
}
