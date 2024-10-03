#include "button.h"

//后面上传两张默认按键图片
Button::Button(int left_, int top_, int right_, int bottom_, const char texture[], const char _texture[]) :
	left(left_), top(top_), right(right_), bottom(bottom_)
{
	_isSelected = false;
	loadimage(&select, _T(texture), 0, 0, false);
	loadimage(&normal, _T(_texture), 0, 0, false);
}

bool Button::isSelected(ExMessage message)
{
	if ((message.x > right || message.x < left) && message.y > top || message.y < bottom)
	{
		_isSelected = true;
		Draw();
		return true;
	}
	_isSelected = false;
	Draw();
	return false;
}

void Button::Draw() const
{
	if (_isSelected)
	{
		putimage(left, top, &select);
	}
	else
	{
		putimage(left, top, &normal);
	}
}
