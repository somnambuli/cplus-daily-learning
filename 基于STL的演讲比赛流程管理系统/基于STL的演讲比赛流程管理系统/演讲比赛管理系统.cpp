#define _CRT_SECURE_NO_WARNINGS
#include "speechManager.h"

int main()
{
	SpeechManager sm;
	int choice;
	while (1)
	{
		sm.show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;

		//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
		//{
		//	cout << "��ţ�" << it->first << " ������ " << it->second.m_name
		//		<< " �ɼ���" << it->second.m_score[0] << endl;
		//}--���Գ�ʼ���Ƿ�ɹ�

		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			break;
		case 3://��ռ�¼
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");//����
			break;
		}
	}

	system("pause");
	return 0;
}