#pragma once
#include <iostream>
#include "olcConsoleGameEngine.h"
#include "Lanes.h"

class Display : public olcConsoleGameEngine
{
public:
	Display();

	void clear();
	void update(float fTimeSinceStart);
	void checkForEvents(float fTimeSinceStart);

private:
	bool isActive;
	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);

	//Lanes
	Map map;

	float fTimeSinceStart = 0.0f;
	//size of each cell
	int nCellSize = 8;
};