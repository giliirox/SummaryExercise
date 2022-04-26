
#include "pch.h"
#include <iostream>
#include "MainSimulator.h"
int main()
{
	MainSimulator* mySim = new MainSimulator();
	mySim->RunAllCameras();
	mySim->PrintDataFromAllCameras();
}
