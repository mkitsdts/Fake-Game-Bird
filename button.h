#ifndef BUTTON_H
#define BUTTON_H
#include <easyx.h>

class Button
{
public:

	Button(int left_, int top_, int right_, int bottom_, const char texture[], const char _texture[]);
	
	//判断有无被选中
	bool isSelected(ExMessage message);
	//绘制按键
	virtual void Draw() const;
private:
	bool _isSelected;
	IMAGE normal;
	IMAGE select;
	//矩形左部x坐标
	int left;
	//矩形顶部y坐标
	int top;
	//矩形右部x坐标
	int right;
	//矩形底部y坐标
	int bottom;
};


#endif // !BUTTON_H

