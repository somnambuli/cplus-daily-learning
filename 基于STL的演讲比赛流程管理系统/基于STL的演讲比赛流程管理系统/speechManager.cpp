#define _CRT_SECURE_NO_WARNINGS
#include "speechManager.h"

//�����๹�캯��ʵ��
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeech();

	//����ѡ��
	this->createSpeaker();

	//��ȡ�����¼
	this->loadRecord();
}

//��������������ʵ��
SpeechManager::~SpeechManager()
{

}

//չʾ�˵�����ʵ��
void SpeechManager::show_Menu()
{
	cout << "********************************" << endl;
	cout << "******* ��ӭ�μ��ݽ����� *******" << endl;
	cout << "*******  1.��ʼ�ݽ�����  *******" << endl;
	cout << "*******  2.�鿴�����¼  *******" << endl;
	cout << "*******  3.��ձ�����¼  *******" << endl;
	cout << "*******  0.�˳���������  *******" << endl;
	cout << "********************************" << endl;
	cout << endl;

}


//�˳�����ʵ��
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��ʼ������
void SpeechManager::initSpeech()
{
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->Victory.clear();
	this->m_Speaker.clear();
	
	//��ʼ����������
	this->m_Index = 1;
}

//����ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}

		//12��ѡ�ֱ��
		this->v1.push_back(i + 10001);
		//ѡ�ֱ�ţ��Լ���Ӧ��ѡ�� ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ����
void SpeechManager::startSpeech()
{
	srand((unsigned int)time(NULL));
	//��һ�ֱ���
	//1.��ǩ
	speechDraw();
	//2.����
	speechContest();
	//3.��ʾ�������
	showScore();
	//�ڶ��ֱ���
	this->m_Index++;
	//1.��ǩ
	speechDraw();
	//2.����
	speechContest();
	//3.��ʾ���ս��
	showScore();
	//4.�������
	saveRecord();
	
	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "��<<" << this->m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	system("pause");
	cout << endl;
	
}

//����
void SpeechManager::speechContest()
{
	cout << "------------------��" << this->m_Index << "����ʽ������ʼ��-----------" << endl;
	multimap<double, int, greater<int>>groupScore;//��ʱ����������key���� valueѡ�ֱ��

	int num = 0;//��¼��Ա����6��Ϊһ��

	vector<int>v_Src;//��������Ա����
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//600-1000
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());//����
		d.pop_front();//ȥ����߷�
		d.pop_back();//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);//��ȡ�ܷ�
		double avg = sum / (double)d.size();//��ȡƽ����

		//ÿ����ƽ����
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;

		//6����һ�� ����ʱ��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin();
				it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->m_Speaker[it->second].m_name
					<< " �ɼ���" << this->m_Speaker[it->second].m_score[this->m_Index - 1] << endl;
			}

			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin();
				it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					Victory.push_back(it->second);
				}
			}

			groupScore.clear();
			cout << endl;
		}

	}

	cout << "---------------��" << this->m_Index << "�ֱ������ -------------" << endl;
	system("pause");
}

//��ʾ��������
void SpeechManager::showScore()
{
	cout << "-----------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�------------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = Victory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ѡ��������" << this->m_Speaker[*it].m_name <<
			" �÷֣�" << this->m_Speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	
}

//�����¼
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//������ķ�ʽ���ļ�--д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = Victory.begin(); it != Victory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
}

//��ȡ��¼����
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	//��ȡ�ĵ����ַ��Ż�ȥ
	ifs.putback(ch);

	string  data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);//��0��ʼ����","
			if (pos == -1)
			{
				break;//�Ҳ���break����
			}
			//�ҵ��ˣ����зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}