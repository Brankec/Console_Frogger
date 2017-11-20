#pragma once
#include <vector>
#include <iostream>


struct Map
{
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
};

