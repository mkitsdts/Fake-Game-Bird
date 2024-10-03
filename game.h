#ifndef GAME_H
#define GAME_H
#include "easyx.h"
#include "button.h"
#include "dinosaur.h"
#include "terrain.h"
#include "main.h"
#include "rectangles.hpp"
#include <memory>
#include <conio.h>
#include <ctime>
#include <iostream>
class Dinosaur;
class Terrain;

class Game
{
public:
	Game();
	virtual ~Game() = default;
	//初始化加载图片并创建地图
	virtual bool Init();
	//准备启动游戏
	bool isGameReady();
	//更新地图状态
	virtual void boundlessUpdate();
	virtual void storyUpdate();
	//游戏开始场景
	void GameReadyScene();
	//
	void GameModeSelectdScene();
	//
	void GameMenuScene();
	//
	void GameEndScene();
	//
	void GameStartScene();
private:
	//管理游戏模式,0为无限模式，1为故事模式
	int gamemode;
	int currentStage;
	//背景
	IMAGE Background;
	IMAGE Title;
	//柱子的图片
	IMAGE Pillars;
	//恐龙的图片
	IMAGE DinosaurUp;
	IMAGE DinosaurDown;
	//鸟和地形的指针
	std::unique_ptr <Dinosaur> dinosaur;
	std::unique_ptr <Terrain> terrain;
	//交互信息（虚拟键码）
	ExMessage operator_num;
};

#endif
