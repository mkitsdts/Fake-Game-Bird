#include "game.h"
using namespace std;

Game::Game()
{
	score = 0;
	dinosaur = make_unique<Dinosaur>();
	//��ʼ����ɽ�����Ϸ׼������
	if (Init())
	{
		GameReadyScene();
	}
}

bool Game::Init()
{
	//���ɿ����͵���
	if (dinosaur && dinosaur.get())
	{
		//��������
		initgraph(WIDTH_MAX, HEIGHT_MAX);
		//����ͼƬ
		loadimage(&Background, _T(".\\resource\\Background.jpg"), 0, 0, false);
		loadimage(&Pillars, _T(".\\resource\\Pillar.png"), 0, 0, false);
		loadimage(&DinosaurUp, _T(".\\resource\\DinosaurUp.png"), 0, 0, false);
		loadimage(&DinosaurDown, _T(".\\resource\\DinosaurDown.png"), 0, 0, false);
		loadimage(&Title, _T(".\\resource\\title.png"), 0, 0, false);
		return true;
	}
	else
	{
		return false;
	}
}

//�����������鲢��ȥ�ƶ���xֵ
void Game::boundlessUpdate()
{
	dinosaur->Update();
	for (auto iter = gamemap.begin(); iter!=gamemap.end();)
	{
		iter->x -= DX;
		if (iter->x <= 0)
		{
			score = score + 1;
			iter = gamemap.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	//����50���ϰ���Ϳ�ʼ����
	while (gamemap.size() < 50)
	{
		terrain->AddCircles();
	}
	cleardevice();
	//������״
	putimage(0, 0, WIDTH_MAX, HEIGHT_MAX, &Background, 0, 0, SRCCOPY);
	setfillstyle(BS_DIBPATTERN, NULL, &Pillars);
	setfillcolor(GREEN);
	for (auto iter = gamemap.begin(); iter->x < WIDTH_MAX; ++iter)
	{
		BeginBatchDraw();
		fillrectangle(iter->x, 0, iter->x + iter->width, iter->height);
		fillrectangle(iter->x, iter->height + 100, iter->x + iter->width, HEIGHT_MAX);
		FlushBatchDraw();
	}
	//������
	if (dinosaur->vertVelocity < 0)
	{
		putimage(dinosaur->positionX, dinosaur->positionY, 32, 32, &DinosaurUp, 0, 0, SRCCOPY);
	}
	else
	{
		putimage(dinosaur->positionX, dinosaur->positionY, 32, 32, &DinosaurDown, 0, 0, SRCCOPY);
	}
	EndBatchDraw();
}

void Game::storyUpdate()
{
	dinosaur->Update();
	for (auto iter = gamemap.begin(); iter != gamemap.end();)
	{
		iter->x -= DX;
		if (iter->x <= 0)
		{
			score = score + 1;
			iter = gamemap.erase(iter);
		}
		else
		{
			++iter;
		}
	}
	cleardevice();
	//������״
	putimage(0, 0, WIDTH_MAX, HEIGHT_MAX, &Background, 0, 0, SRCCOPY);
	setfillstyle(BS_DIBPATTERN, NULL, &Pillars);
	for (auto iter = gamemap.begin(); iter->x < WIDTH_MAX; ++iter)
	{
		BeginBatchDraw();
		if (iter->x + iter->width >= 960)
		{
			fillrectangle(iter->x, 0, WIDTH_MAX, iter->height);
			fillrectangle(iter->x, iter->height + 100, WIDTH_MAX, HEIGHT_MAX);
		}
		else
		{
			fillrectangle(iter->x, 0, iter->x + iter->width, iter->height);
			fillrectangle(iter->x, iter->height + 100, iter->x + iter->width, HEIGHT_MAX);
		}
		FlushBatchDraw();
	}
	//������
	if (dinosaur->vertVelocity < 0)
	{
		putimage(dinosaur->positionX, dinosaur->positionY, 32, 32, &DinosaurUp, 0, 0, SRCCOPY);
	}
	else
	{
		putimage(dinosaur->positionX, dinosaur->positionY, 32, 32, &DinosaurDown, 0, 0, SRCCOPY);
	}
	EndBatchDraw();
}

bool Game::isGameReady()
{
	//��ȡ�������룬���س�����ʼ��Ϸ
	while(true)
	{
		if (peekmessage(&operator_num, EX_KEY))
		{
			if (operator_num.vkcode == 0x0D)
			{
				return true;
			}
		}
	}
}

void Game::GameReadyScene()
{
	//�ı�����
	settextcolor(BLACK);
	setbkmode(WHITE);
	BeginBatchDraw();
	putimage(0, 0, WIDTH_MAX, HEIGHT_MAX, &Background, 0, 0, SRCCOPY);
	putimage(WIDTH_MAX / 2 - 148, HEIGHT_MAX / 2 - 30, 296, 65, &Title, 0, 0, SRCCOPY);
	//outtextxy(WIDTH_MAX / 2, 3 * HEIGHT_MAX / 4, "Press enter to start game.");
	EndBatchDraw();
	//���س�����ʼ��Ϸ
	if (isGameReady())
	{
		GameModeSelectdScene();
	}
}

void Game::GameModeSelectdScene()
{
	//��������
	auto storyMode = make_unique <Button>(WIDTH_MAX / 2 - 100, 35,WIDTH_MAX / 2 + 100, 235,
		".\\resource\\StoryModeSelected.png", ".\\resource\\StoryModeNormal.png");
	auto boundlessMode = make_unique <Button>(WIDTH_MAX / 2 - 100, 305,WIDTH_MAX / 2 + 100, 505,
		".\\resource\\BoundlessModeSelected.png", ".\\resource\\BoundlessModeNormal.png");
	cleardevice();
	//���Ʊ���
	BeginBatchDraw();
	putimage(0, 0, &Background);
	//���ư���
	storyMode->Draw();
	boundlessMode->Draw();
	EndBatchDraw();
	while (true)
	{
		if (peekmessage(&operator_num, EX_MOUSE))
		{
			if (operator_num.lbutton == 1)
			{
				//ѡ�����ģʽ
				if (storyMode->isSelected(operator_num))
				{
					gamemode = 1;
					GameMenuScene();
					break;
				}
				//ѡ������ģʽ
				else if (boundlessMode->isSelected(operator_num))
				{
					gamemode = 0;
					terrain = make_unique<Terrain>();
					GameStartScene();
				}
			}
		}
	}
}

void Game::GameMenuScene()
{
	auto firstStage = make_unique <Button>(46, HEIGHT_MAX / 2 - 50, 146, HEIGHT_MAX / 2 + 50,
		".\\resource\\firstStageSelected.png", ".\\resource\\firstStageNormal.png");
	auto secondStage = make_unique <Button>(238, HEIGHT_MAX / 2 - 50, 338, HEIGHT_MAX / 2 + 50,
		".\\resource\\secondStageSelected.png", ".\\resource\\secondStageNormal.png");
	auto thirdStage = make_unique <Button>(384, HEIGHT_MAX / 2 - 50, 484, HEIGHT_MAX / 2 + 50,
		".\\resource\\thirdStageSelected.png", ".\\resource\\thirdStageNormal.png");
	auto fourthStage = make_unique <Button>(530, HEIGHT_MAX / 2 - 50, 630, HEIGHT_MAX / 2 + 50,
		".\\resource\\fourthStageSelected.png", ".\\resource\\fourthStageNormal.png");
	auto fifthStage = make_unique <Button>(676, HEIGHT_MAX / 2 - 50, 876, HEIGHT_MAX / 2 + 50,
		".\\resource\\fifthStageSelected.png", ".\\resource\\fifthStageNormal.png");
	terrain = make_unique<Terrain>();
	cleardevice();
	//���Ʊ���
	BeginBatchDraw();
	putimage(0, 0, &Background);
	//���ư���
	firstStage->Draw();
	secondStage->Draw();
	thirdStage->Draw();
	fourthStage->Draw();
	fifthStage->Draw();
	EndBatchDraw();
	while (true)
	{
		if (peekmessage(&operator_num, EX_MOUSE))
		{
			if (operator_num.lbutton == 1)
			{
				if (firstStage->isSelected(operator_num))
				{
					currentStage = 1;
					terrain = make_unique<Terrain>(1);
					GameStartScene();
				}
				else if (secondStage->isSelected(operator_num))
				{
					currentStage = 2;
					terrain = make_unique<Terrain>(2);
					GameStartScene();
				}
				else if (thirdStage->isSelected(operator_num))
				{
					currentStage = 3;
					terrain = make_unique<Terrain>(3);
					GameStartScene();
				}
				else if (fourthStage->isSelected(operator_num))
				{
					currentStage = 4;
					terrain = make_unique<Terrain>(4);
					GameStartScene();
				}
				else if (fifthStage->isSelected(operator_num))
				{
					currentStage = 5;
					terrain = make_unique<Terrain>(5);
					GameStartScene();
				}
			}
		}
	}
	GameStartScene();
}

void Game::GameStartScene()
{
	while (true)
	{
		if (!dinosaur->isDeath())
		{
			if (peekmessage(&operator_num, EX_KEY))
			{
				//����ո�����
				if (operator_num.vkcode == 0x20)
				{
					dinosaur->Up();
				}
				//����D�����
				else if (operator_num.vkcode == 0x44)
				{
					if (DX > 0)
						DX = DX + 1;
				}
				//����A�����
				else if (operator_num.vkcode == 0x41)
				{
					if (DX > 0)
						DX = DX - 1;
				}
				//����Esc������һ��
				else if (operator_num.vkcode == 0x1B)
				{
					GameModeSelectdScene();
				}
			}
			if (gamemode == 0)
			{
				boundlessUpdate();
			}
			else
			{
				storyUpdate();
			}
		}
		else
		{
			GameEndScene();
		}
		Sleep(10);
	}
}

void Game::GameEndScene()
{
	char num[20];
	sprintf_s(num, "%d", score);
	cleardevice();
	putimage(0, 0, WIDTH_MAX, HEIGHT_MAX, &Background, 0, 0, SRCCOPY);
	setbkmode(WHITE);
	outtextxy(WIDTH_MAX / 2, HEIGHT_MAX / 4, "Your Score");
	outtextxy(WIDTH_MAX / 2, HEIGHT_MAX / 3, num);
	outtextxy(WIDTH_MAX / 2, HEIGHT_MAX / 2, "Game Over");
	while (true)
	{
		if (peekmessage(&operator_num, EX_KEY))
		{
			score = 0;
			dinosaur.release();
			terrain.release();
			dinosaur = make_unique<Dinosaur>();
			GameMenuScene();
		}
	}
}
