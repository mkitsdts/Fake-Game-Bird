#include "terrain.h"

Terrain::Terrain() 
{
	int tempx = 900;
	for (int i = 0; i < 50; ++i)
	{
		//需要的数字有矩形左上角顶点的x值，矩形的高度，矩形的宽度，两个矩形之间的间隔，
		//x的范围
		int tempHeight = RandomNum(1, 380);
		int tempWidth = RandomNum(10, 40);
		tempx = tempx + RandomNum(150, 300);
		gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
	}
}

Terrain::~Terrain()
{
}


int Terrain::RandomNum(int _min, int _max)
{
	std::random_device rd;
	srand(rd());
	int n = rand() % _max + _min;
	return n;
}

void Terrain::AddCircles()
{
	int tempHeight = RandomNum(1, 380);
	int tempWidth = RandomNum(10, 40);
	int tempx = gamemap.rbegin()->x + RandomNum(150, 300);
	gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
}

