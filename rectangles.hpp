#ifndef RECTANGLES_HPP
#define RECTANGLES_HPP
/*
这里存放辅助作用的函数
*/

struct Rectangles
{
	Rectangles(int _x, int _width, int _height)
	{
		x = _x;
		width = _width;
		height = _height;
	}
	int x;
	int width;
	int height;
};

#endif

