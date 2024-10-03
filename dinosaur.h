#ifndef Dinosaur_H
#define Dinosaur_H
#include "rectangles.hpp"
#include "easyx.h"
#include "main.h"
class Dinosaur
{
public:

	Dinosaur();
	virtual ~Dinosaur();

	bool isDeath() const;
	//����λ��
	virtual void Update();

	//�ı��ٶȷ���
	void Up();

public:
	//��ֱ�����ٶ�
	int vertVelocity;
	//��x��yΪ���ϽǵĶ���
	int positionX = 100;
	int positionY = 100;
	const int length = 32;
};


#endif

