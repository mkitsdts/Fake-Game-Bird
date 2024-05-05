#ifndef Dinosaur_H
#define Dinosaur_H
#include "rectangles.hpp"
#include "main.h"
class Dinosaur
{
public:

	Dinosaur();
	virtual ~Dinosaur();


	//更新位置
	virtual void Update();

	//改变速度方向
	void Up();

public:
	//竖直方向速度
	int vertVelocity;
	//点x，y为左上角的顶点
	const int positionX = 100;
	int positionY = 100;
	const int length = 40;
};


#endif Dinosaur_H

