#include "game.h"

Game::~Game()
{
}

Game::Game()
{
	dinosaur = new Dinosaur;
	terrain = new Terrain;
	operator_num = 0;
	if (Init())
	{
		if (isGameReady())
			GameStart();
	}
}

bool Game::Init()
{
	//生成恐龙和地形
	if (dinosaur && terrain)
	{
		DrawReadyScene();
		return true;
	}
	return false;
}

void Game::GameStart()
{
	while (true)
	{
		if (!isDeath())
		{
			if (_kbhit())
			{
				operator_num = _getch();
				if (operator_num == ' ')
				{
					dinosaur->Up();
				}
			}
			Update();
			cleardevice();
			DrawScene();
		}
		else
		{
			DrawEndScene();
			if (_kbhit())
			{
				closegraph();
				break;
			}
		}
		Sleep(2);
	}
}

void Game::DrawScene()
{
	BeginBatchDraw();
	setfillstyle(BS_SOLID);
	setfillcolor(GREEN);
	/*

	*/
	//画矩形状
	for (auto iter = gamemap.begin(); iter->x < WIDTH_MAX; ++iter)
	{
		fillrectangle(iter->x, 0, iter->x + iter->width, iter->height);
		fillrectangle(iter->x, iter->height + 100, iter->x + iter->width, HEIGHT_MAX);
	}
	solidrectangle(dinosaur->positionX, dinosaur->positionY,
		dinosaur->positionX + dinosaur->length, dinosaur->positionY + dinosaur->length);

	EndBatchDraw();
}

//遍历矩形数组并减去移动的x值
void Game::Update()
{
	dinosaur->Update();
	for (auto iter = gamemap.begin(); iter!=gamemap.end(); ++iter)
	{
		iter->x -= DX;
		if (iter->x <= 0)
		{
			iter = gamemap.erase(gamemap.begin());
			continue;
		}
	}
	//少于50个障碍物就开始增加
	while (gamemap.size() < 50)
	{
		terrain->AddCircles();
	}
}

bool Game::isDeath() const
{
	if (dinosaur->positionY <= 0 || dinosaur->positionY >= HEIGHT_MAX)
	{
		return true;
	}
	for (auto iter = gamemap.begin(); iter->x < WIDTH_MAX / 4; ++iter)
	{
		//上方矩形
		if (dinosaur->positionX + dinosaur->length >= iter->x && dinosaur->positionX <= iter->x + iter->width)
		{
			if (dinosaur->positionY <= iter->height || dinosaur->positionY >= (100 + iter->height))
			{
				return true;
			}
		}
	}
	return false;
}

bool Game::isGameReady()
{
	//获取键盘输入，按回车键开始游戏
	while (true)
	{
		if (_kbhit())
		{
			operator_num = _getch();
			if (operator_num == 13)
			{
				cleardevice();
				DrawScene();
				return true;
			}
		}
	}
}

void Game::DrawReadyScene()
{

	//创建窗口
	initgraph(WIDTH_MAX, HEIGHT_MAX, EX_NOMINIMIZE | EX_SHOWCONSOLE);
	//文本赛车
	settextcolor(RED);
	outtextxy(WIDTH_MAX / 2, HEIGHT_MAX / 2, L"GenShin Impact");

}

void Game::DrawEndScene()
{
	cleardevice();
	settextcolor(RED);
	outtextxy(WIDTH_MAX / 2, HEIGHT_MAX / 2, L"Game Over");
}
