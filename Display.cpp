#include "Display.h"

Display::Display()
{
	m_sAppName = L"Frogger";

	isActive = true;
}

void Display::clear()
{	
}

void Display::update(float fTimeSinceStart)
{
	int x = -1, y = 0;
	for (auto lane : map.vecLanes)
	{
		// Find offset
		int nStartPos = (int)(fTimeSinceStart * lane.first) % 64;
		if (nStartPos < 0) nStartPos = 64 - (abs(nStartPos) % 64); // so we dont have negative values in wChar_t graphic line of code

		int nCellOffset = (int)((float)nCellSize * fTimeSinceStart * lane.first) % nCellSize;

		for (int i = 0; i < (ScreenWidth() / nCellSize) + 2; i++)
		{
			wchar_t graphic = lane.second[(nStartPos + i) % 64];
			Fill((x + i) * nCellSize - nCellOffset, y*nCellSize, (x + i + 1)*nCellSize - nCellOffset, (y + 1) * nCellSize, graphic);
		}

		y++;
	}
}

void Display::checkForEvents(float fTimeSinceStart)
{
}

bool Display::OnUserCreate()
{
	return true;
}

bool Display::OnUserUpdate(float fElapsedTime)
{
	fTimeSinceStart += fElapsedTime;

	// Draw Lanes
	update(fTimeSinceStart);

	// Controls
	checkForEvents(fTimeSinceStart);

	return true;
}

