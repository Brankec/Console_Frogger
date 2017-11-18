#include <iostream>
#include <vector>
#include "olcConsoleGameEngine.h"

class Frogger : public olcConsoleGameEngine
{
public:
	Frogger()
	{
		m_sAppName = L"Frogger";
	}
private:
	//Lanes
	std::vector<std::pair<float, std::wstring>> vecLanes =
	{
		{ 0.0f,  L"xxx  xxx  xxx  xxx                                              " }, //end        64 elements per lane
		{ -3.0f, L"   xxxx  xxxxxx       xxxx     xx   xxxxx    xxxxxx    xxxxx    " }, //logs
		{ 3.0f,  L"    xxxx     xxxx    xxxx         xxxx     xx      xxxxxx       " }, //logs
		{ 2.0f,  L"  xxx     xxx     xx     xxx   xxx    xx    xxxx    xx      xx  " }, //logs
		{ 0.0f,  L"                                                                " },
		{ -3.0f, L"    xx       xx    xx          xx      xx            xx    xx   " }, //cars
		{ 3.0f,  L"   xxxx       xxxx       xxxx      xxxx  xxxx      xxxx     xxxx" }, //bus
		{ -4.0f, L"  xx     xx         xx  xx        xx   xx   xx    xx   xx   xx  " }, //cars
		{ 2.0f,  L"  xx     xx       xx     xx      xx  xx xx       xx    xx       " }, //cars
		{ 0.0f,  L"                                                                " }  //start
	};

	float fTimeSinceStart = 0.0f;
	//size of each cell
	int nCellSize = 8;

protected:
	virtual bool OnUserCreate()
	{
		return true;
	}
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		fTimeSinceStart += fElapsedTime;

		// Draw Lanes
		int x = -1, y = 0;
		for (auto lane : vecLanes)
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

		return true;
	}
};

int main()
{
	Frogger game;
	game.ConstructConsole(128, 80, 12, 12);
	game.Start();

	return 0;
}