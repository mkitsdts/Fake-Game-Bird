#ifndef TERRAIN_H
#define TERRAIN_H
#include "easyx.h"
#include "main.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

/*
* ����һ��X*X(XΪż��)�Ĵ��� ��ÿ360Ϊһ����λ������״ ����ֱ�� x = width / 4 ������������ ���¹�40��������
* ��������ÿ��������λȡһ����
* Ҫ���ǵ��ƶ���λ�������ε��������ʱ�������ɹ����
*/

class Terrain
{
public:
	//960*540�Ļ���
	//��Ĵ�С40*40
	//����һ��0��380�������������θ߶�
	//�����50��80֮��
	//��϶100
	//�м���100��200
	//������ϣ������α�����

	Terrain();
	Terrain(int n);
	virtual ~Terrain() = default;

	//���ɷ�Χ�������
	int RandomNum(int _min, int _max);
	//����µľ���
	void AddCircles();
private:
	std::default_random_engine rd;
};

#endif
