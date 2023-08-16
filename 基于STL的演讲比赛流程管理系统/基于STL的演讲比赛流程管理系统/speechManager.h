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

//�ݽ�������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void show_Menu();

	//�˳�����
	void exitSystem();

	//����ѡ��
	void createSpeaker();

	//��ʼ������
	void initSpeech();

	//��ʼ����--�������̿���
	void startSpeech();

	//��ǩ
	void speechDraw();
	//����
	void speechContest();
	//��ʾ��������
	void showScore();
	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();


	//��������
	~SpeechManager();

public:

	//����ѡ������ 12��
	vector<int>v1;

	//��һ�ֽ������� 6��
	vector<int>v2;

	//ʤ��ǰ�������� 3��
	vector<int>Victory;

	//��ű�� �Լ���Ӧ�ľ���ѡ������
	map<int, Speaker>m_Speaker;

	//��������
	int m_Index;

	//�ļ�Ϊ�յı�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>>m_Record;
};


