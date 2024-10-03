#ifndef SCORE_HPP
#define SCORE_HPP

#include "main.h"
#include <string>
#include <fstream>
#include <cassert>
#include <string_view>
#include <algorithm>

class Score
{
public:
	//�����ļ�
	Score();
	~Score() = default;

	//��ȡ�ļ�����
	void FileRead();
	//����������
	void ScoreSort();

private:
	std::fstream scoreFile;
	int to_int(std::string_view str);
	bool bmp();
};

Score::Score()
{
	//�����������û���򴴽�
	scoreFile.open(".\score\score.txt", std::ios::out);
	assert(!scoreFile.is_open());
	scoreFile.close();
}

inline void Score::FileRead()
{
	int _score = 0;
	std::string tmp;
	while (!scoreFile.eof())
	{
		getline(scoreFile,tmp);
		//��������ܵĲ�Ϊ0
		assert(!allscore.capacity());
		allscore.push_back(to_int(std::string_view(tmp)));
	}
}

inline void Score::ScoreSort()
{

}

inline int Score::to_int(std::string_view str)
{
	int tmp = 0;
	int n = 0;
	for (auto iter=str.rbegin(); iter!=str.rend(); ++iter,++n)
	{
		tmp += *iter * (int)pow(10, n);
	}
	return tmp;
}
inline bool Score::bmp()
{

	return false;
}
#endif // !SCORE_HPP
