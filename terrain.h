#ifndef TERRAIN_H
#define TERRAIN_H
#include "easyx.h"
#include "main.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

/*
* 创建一个X*X(X为偶数)的窗口 以每360为一个单位正方形状 根据直线 x = width / 4 生成噪声地形 上下共40个正方形
* 正方形内每隔两个单位取一个点
* 要考虑到移动部位整正方形的情况，此时不能生成过多点
*/

class Terrain
{
public:
	//960*540的画布
	//鸟的大小40*40
	//生成一个0到380的随机数代表矩形高度
	//宽度在50到80之间
	//缝隙100
	//中间间隔100到200
	//建立哈希表生成伪随机数

	Terrain();
	Terrain(int n);
	virtual ~Terrain() = default;

	//生成范围内随机数
	int RandomNum(int _min, int _max);
	//添加新的矩形
	void AddCircles();
private:
	std::default_random_engine rd;
};

#endif
