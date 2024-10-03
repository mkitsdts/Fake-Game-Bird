#ifndef SCENE_H
#define SCENE_H
#include <queue>
#include <button.h>
#include <string_view>
#include <string>
using std::queue;
using std::string;
using std::string_view;

class Scene
{
public:
	Scene();
	~Scene() = default;
	//���ӽڵ�
	void Add(Button* tmp);
	void Add(IMAGE* tmp);
	void Add(string_view str);
	//���Ƴ���
	virtual void Draw();

private:
	queue <Button*> buttons;
	queue <IMAGE*> images;
	queue <string> textures;

};


#endif //SCENE_H
