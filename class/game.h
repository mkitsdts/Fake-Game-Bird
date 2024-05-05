#ifndef GAME_H
#define GAME_H
#include "easyx.h"
#include "graphics.h"
#include "dinosaur.h"
#include "terrain.h"
#include "main.h"
#include "rectangles.hpp"
#include <conio.h>
#include <ctime>

class Dinosaur;
class Terrain;

class Game
{
public:

	Game();
	virtual ~Game();

	//初始化加载图片并创建地图
	virtual bool Init();
	//准备启动游戏
	bool isGameReady();
	//绘制准备游戏界面
	void DrawReadyScene();
	//绘制结束界面
	void DrawEndScene();
	//启动游戏
	void GameStart();
	//绘制新图
	void DrawScene();
	//更新地图状态
	virtual void Update();
	//判断是否死亡
	bool isDeath() const;

private:
	Dinosaur* dinosaur;
	Terrain* terrain;
	char operator_num;
};

#endif GAME_HPP
