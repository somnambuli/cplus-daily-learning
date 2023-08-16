#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
#include<ctime>
#include "Speaker.h"
using namespace std;

//演讲管理类
class SpeechManager
{
public:
	//构造函数
	SpeechManager();

	//展示菜单
	void show_Menu();

	//退出功能
	void exitSystem();

	//创建选手
	void createSpeaker();

	//初始化属性
	void initSpeech();

	//开始比赛--比赛流程控制
	void startSpeech();

	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示比赛分数
	void showScore();
	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();


	//析构函数
	~SpeechManager();

public:

	//比赛选手容器 12人
	vector<int>v1;

	//第一轮晋级容器 6人
	vector<int>v2;

	//胜利前三名容器 3人
	vector<int>Victory;

	//存放编号 以及对应的具体选手容器
	map<int, Speaker>m_Speaker;

	//比赛轮数
	int m_Index;

	//文件为空的标志
	bool fileIsEmpty;

	//往届记录
	map<int, vector<string>>m_Record;
};


