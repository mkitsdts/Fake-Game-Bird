#ifndef BUTTON_H
#define BUTTON_H
#include <easyx.h>

class Button
{
public:

	Button(int left_, int top_, int right_, int bottom_, const char texture[], const char _texture[]);
	
	//�ж����ޱ�ѡ��
	bool isSelected(ExMessage message);
	//���ư���
	virtual void Draw() const;
private:
	bool _isSelected;
	IMAGE normal;
	IMAGE select;
	//������x����
	int left;
	//���ζ���y����
	int top;
	//�����Ҳ�x����
	int right;
	//���εײ�y����
	int bottom;
};


#endif // !BUTTON_H

