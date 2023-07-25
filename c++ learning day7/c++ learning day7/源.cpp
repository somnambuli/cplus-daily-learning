#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
using namespace std;

#if 0
//vector�����ɾ��
void PrintDeque(const deque<int>& D)
{
	for (deque<int>::const_iterator it = D.begin(); it != D.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);

	d1.pop_back();
	PrintDeque(d1);

	d1.insert(d1.begin()+2, 9);
	PrintDeque(d1);

	d1.insert(d1.end(), 2, 1);
	PrintDeque(d1);

	d1.erase(d1.begin());
	PrintDeque(d1);

	d1.clear();
	PrintDeque(d1);


}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//deque���ݴ�ȡ--��deque�е����ݵĴ�ȡ����
void PrintDeque(const deque<int>& D)
{
	for (deque<int>::const_iterator it = D.begin(); it != D.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);

	cout << "�����ڵ��ĸ���Ϊ��" << d1.at(3) << endl;
	cout << "�����ڵ�������Ϊ��" << d1[2] << endl;
	cout << "�����ڵ�һ����Ϊ��" << d1.front() << endl;
	cout << "���������һ����Ϊ��" << d1.back() << endl;

}


int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//deque��������
void PrintDeque(const deque<int>& D)
{
	for (deque<int>::const_iterator it = D.begin(); it != D.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(50);
	d1.push_back(70);
	d1.push_back(35);
	PrintDeque(d1);

	sort(d1.begin(), d1.end());
	PrintDeque(d1);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//����--��ί���
/*
* ��5��ѡ�֣�ѡ��ABCD��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ͷ֣�ȡƽ����
* ʵ�ֲ��裺
* 1.��������ѡ�֣��ŵ�vector��
* 2.����vecotr������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�ʮ����ί��ִ浽deque������
* 3.sort������deque�����з�������ȥ����ߺ����
* 4.deque��������һ�飬�ۼ��ܷ�
* 5.��ȡƽ����
*/


void test01()
{
	//�������vector�����Լ�С��deque����
	vector<deque<int>>v;
	deque<int>v1;
	deque<int>v2;
	deque<int>v3;
	deque<int>v4;
	deque<int>v5;
	int sum = 0;
	srand((unsigned)time(NULL));

	//��С����deque���ݸ�ֵ
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 41 + 60);
		v2.push_back(rand() % 41 + 60);
		v3.push_back(rand() % 41 + 60);
		v4.push_back(rand() % 41 + 60);
		v5.push_back(rand() % 41 + 60);
	}
	//�Դ�����vector��ֵ
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	//��deque�����ڵ���ֵ��������ɾ����һ�����һ��
	//�����������������������ƽ��ֵ ��ƽ��ֵ�ŵ����һ��λ��
	for (vector<deque<int>>::iterator it= v.begin(); it != v.end(); it++)
	{
		sort((*it).begin(), (*it).end());
		(*it).pop_back();
		(*it).pop_front();
		sum = 0;
		for (deque<int>::const_iterator dit = (*it).begin(); dit != (*it).end(); dit++)
		{
			sum += *dit;
		}
		(*it).push_back(sum/8);
		cout << sum / 8 << endl;
	}

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//stack����---�Ƚ���������ݽṹ��ջ��
void test01()
{
	stack<int>s1;
	for (int i = 0; i < 10; i++)
	{
		s1.push(i);
	}
	stack<int>s2(s1);
	stack<int>s3 = s2;
	s1.pop();
	cout << "s1��ջ��Ԫ��Ϊ��" << s1.top() << endl;
	if (s1.empty() != 1)
	{
		cout << "������Ϊ�գ�" << endl;
	}

	cout << "�����Ĵ�СΪ��" << s1.size() << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//queue����

class Person
{
public:
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}

	string m_name;
	int m_age;
};

void test01()
{
	queue<Person> q;

	//׼������
	Person p1("��ɮ", 30);
	Person p2("�����", 999);
	Person p3("��˽�", 878);
	Person p4("ɳɮ", 367);

	//����������Ԫ�� ���Ԫ��
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "���д�СΪ:" << q.size() << endl;

	//���в��ṩ������������֧���������
	while (!q.empty())
	{
		//�����ͷԪ��
		cout << "��ͷԪ��--������" << q.front().m_name << " ���� " << q.front().m_age << endl;
		//�����βԪ��
		cout << "��βԪ��--������" << q.back().m_name << " ���� " << q.back().m_age << endl;

		cout << "---------------------------" << endl;
		q.pop();
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//list����
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);

	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	list<int>L3(L1);
	printList(L3);

	list<int>L4(4, 30);
	printList(L4);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//list��ֵ�ͽ���
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);

	list<int>L2;
	L2 = L1;
	printList(L2);

	list<int>L3;
	L3.assign(L1.begin(), L1.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 130);
	printList(L4);

}

void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);

	list<int>L2;
	L2.assign(6, 10);
	printList(L2);

	L1.swap(L2);

	cout << "������" << endl;
	printList(L1);
	printList(L2);

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

#elif 0
//list�����Ĵ�С����
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);

	if (L1.empty())
	{
		cout<<"����Ϊ�գ�"<<endl;
	}
	else
	{
		cout << "������Ϊ�գ�" << endl;
		cout << "�����Ĵ�СΪ��" << L1.size() << endl;
	}

	//����ָ����С
	L1.resize(3);
	printList(L1);

	L1.resize(10);
	printList(L1);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 1
//list�����ɾ��
//��list�����������ݵĲ����ɾ��

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L;
	//β��
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//ͷ��
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	//βɾ
	L.pop_back();
	printList(L);

	//ͷɾ
	L.pop_front();
	printList(L);

	//����
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	//ɾ��
	L.erase(it);
	printList(L);

	//�Ƴ�
	L.push_back(1000);
	L.push_back(1000);
	L.push_back(1000);
	printList(L);
	L.remove(1000);
	printList(L);


	//���
	L.clear();
	printList(L);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#endif