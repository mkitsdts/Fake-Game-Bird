#include "terrain.h"

Terrain::Terrain() 
{
	rd.seed(time(0));
	int tempx = 900;
	for (int i = 0; i < 50; ++i)
	{
		//��Ҫ�������о������ϽǶ����xֵ�����εĸ߶ȣ����εĿ�ȣ���������֮��ļ����
		//x�ķ�Χ
		int tempHeight = RandomNum(1, 380);
		int tempWidth = RandomNum(10, 40);
		tempx = tempx + RandomNum(150, 300);
		gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
	}
}

Terrain::Terrain(int n)
{
	rd.seed(time(0));
	int tempx = 900;
	switch (n)
	{
	case 1:
		for (int i = 0; i < 100; ++i)
		{
			//��Ҫ�������о������ϽǶ����xֵ�����εĸ߶ȣ����εĿ�ȣ���������֮��ļ����
			//x�ķ�Χ
			int tempHeight = 200;
			int tempWidth = RandomNum(10, 30);
			tempx = tempx + RandomNum(300, 350);
			gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
			break;
		}
	case 2:
		for (int i = 0; i < 100; ++i)
		{
			//��Ҫ�������о������ϽǶ����xֵ�����εĸ߶ȣ����εĿ�ȣ���������֮��ļ����
			//x�ķ�Χ
			int tempHeight = RandomNum(1, 380);
			int tempWidth = RandomNum(10, 40);
			tempx = tempx + RandomNum(150, 300);
			gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
			break;
		}
	case 3:
		for (int i = 0; i < 100; ++i)
		{
			//��Ҫ�������о������ϽǶ����xֵ�����εĸ߶ȣ����εĿ�ȣ���������֮��ļ����
			//x�ķ�Χ
			int tempHeight = RandomNum(1, 380);
			int tempWidth = RandomNum(10, 40);
			tempx = tempx + RandomNum(150, 300);
			gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
			break;
		}
	case 4:
		for (int i = 0; i < 100; ++i)
		{
			//��Ҫ�������о������ϽǶ����xֵ�����εĸ߶ȣ����εĿ�ȣ���������֮��ļ����
			//x�ķ�Χ
			int tempHeight = RandomNum(1, 380);
			int tempWidth = RandomNum(10, 40);
			tempx = tempx + RandomNum(150, 300);
			gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
			break;
		}
	case 5:
		for (int i = 0; i < 100; ++i)
		{
			//��Ҫ�������о������ϽǶ����xֵ�����εĸ߶ȣ����εĿ�ȣ���������֮��ļ����
			//x�ķ�Χ
			int tempHeight = RandomNum(1, 380);
			int tempWidth = RandomNum(10, 40);
			tempx = tempx + RandomNum(150, 300);
			gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
			break;
		}
	}
}

int Terrain::RandomNum(int _min, int _max)
{
	int n = rd() % (_max - _min + 1) + _min;
	return n;
}

void Terrain::AddCircles()
{
	int tempHeight = RandomNum(1, 380);
	int tempWidth = RandomNum(10, 40);
	int tempx = gamemap.rbegin()->x + RandomNum(150, 300);
	gamemap.push_back(Rectangles(tempx, tempWidth, tempHeight));
}

