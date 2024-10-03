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
	//��ʼ������ͼƬ��������ͼ
	virtual bool Init();
	//׼��������Ϸ
	bool isGameReady();
	//���µ�ͼ״̬
	virtual void boundlessUpdate();
	virtual void storyUpdate();
	//��Ϸ��ʼ����
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
	//������Ϸģʽ,0Ϊ����ģʽ��1Ϊ����ģʽ
	int gamemode;
	int currentStage;
	//����
	IMAGE Background;
	IMAGE Title;
	//���ӵ�ͼƬ
	IMAGE Pillars;
	//������ͼƬ
	IMAGE DinosaurUp;
	IMAGE DinosaurDown;
	//��͵��ε�ָ��
	std::unique_ptr <Dinosaur> dinosaur;
	std::unique_ptr <Terrain> terrain;
	//������Ϣ��������룩
	ExMessage operator_num;
};

#endif
