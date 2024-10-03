#include "scene.h"
#include "memory"
using namespace std;

Scene::Scene()
{

}

void Scene::Add(Button* tmp)
{
	buttons.push(tmp);
}

void Scene::Add(IMAGE* tmp)
{
	images.push(tmp);
}

void Scene::Add(string_view str)
{
	string str_(str);
	textures.push(str_);
}

void Scene::Draw()
{
	cleardevice();
	BeginBatchDraw();
	while (!images.empty())
	{

	}
	while (!buttons.empty())
	{

	}
	while (!textures.empty())
	{

	}
	EndBatchDraw();
}
