#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

#if 0

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m;//Ĭ�Ϲ���
	m.insert(pair<int, int>(1, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 50));
	m.insert(pair<int, int>(4, 40));

	printMap(m);
	
	//��������
	map<int, int>m2(m);
	printMap(m2);

	//��ֵ����
	map<int, int>m3;
	m3 = m;
	printMap(m3);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//map��С�ͽ���--ͳ��map������С�Լ�����map����

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty())
	{
		cout << "map����mΪ�գ�" << endl;
	}
	else
		cout << "map����m��Ϊ�գ���СΪ��" << m.size() << endl;

}

//����
void test02()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));

	cout << "����ǰ��" << endl;
	printMap(m1);
	printMap(m2);

	cout << "������" << endl;
	m1.swap(m2);
	printMap(m1);
	printMap(m2);

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}


#elif 0
//map�����ɾ��--��map�������в������ݺ�ɾ������
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	//����
	map<int, int>m;
	//��һ�ֲ��뷽ʽ
	m.insert(pair<int, int>(1, 10));
	//�ڶ��ֲ��뷽ʽ
	m.insert(make_pair(2, 20));
	//�����ֲ��뷽ʽ
	m.insert(map<int, int>::value_type(3, 30));
	//�����ֲ��뷽ʽ
	m[4] = 40;

	printMap(m);

	//ɾ��
	m.erase(m.begin());
	printMap(m);

	m.erase(30);//����ɾ����ʽ�Ƕ�keyֵ��������
	printMap(m);

	//���
	m.clear();
	printMap(m);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//map���Һ�ͳ��--��map�������в��������Լ�ͳ������
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	//����
	map<int, int>::iterator it = m1.find(3);
	if (it != m1.end())
	{
		cout << "�ҵ�keyֵΪ3��Ԫ�أ�" << it->second << endl;
	}
	else
	{
		cout << "��ֵ������" << endl;
	}

	//ͳ��
	int num = m1.count(3);
	cout << "num = " << num << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//map��������
//map����Ĭ���������Ϊ����keyֵ���д�С��������������θı��������
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};

void printMap2(map<int, int, MyCompare>& M)
{
	for (map<int, int, MyCompare>::iterator it = M.begin(); it != M.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}



void test01()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(3, 10));
	m1.insert(pair<int, int>(2, 10));
	m1.insert(pair<int, int>(4, 10));

	printMap(m1);

	map<int, int, MyCompare>m2;
	m2.insert(pair<int, int>(5, 20));
	m2.insert(pair<int, int>(1, 10));
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(3, 70));
	m2.insert(pair<int, int>(2, 30));
	printMap2(m2);

}

int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string name;
	int salary;
};

void CreateWorker(vector<Worker>& v)
{
	string name = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.name = "Ա��";
		worker.name += name[i];
		worker.salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}


void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int bianhao = rand() % 3;
		m.insert(pair<int, Worker>(bianhao, *it));
	}
}

void showWorkerGroup(multimap<int, Worker>& m)
{

	cout << "�߻����ţ�" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int num = m.count(CEHUA);
	for (int i = 0; i < num; i++, pos++)
	{
		if (pos != m.end())
		{
			cout << " ������" << pos->second.name << " ����" << pos->second.salary << endl;
		}
	}

	cout << "--------------------------------" << endl;

	cout << "�������ţ�" << endl;
	pos = m.find(MEISHU);
	num = m.count(MEISHU);
	for (int i = 0; i < num; i++, pos++)
	{
		if (pos != m.end())
		{
			cout << " ������" << pos->second.name << " ����" << pos->second.salary << endl;
		}
	}

	cout << "--------------------------------" << endl;

	cout << "�з����ţ�" << endl;
	pos = m.find(YANFA);
	num = m.count(YANFA);
	for (int i = 0; i < num; i++, pos++)
	{
		if (pos != m.end())
		{
			cout << " ������" << pos->second.name << " ����" << pos->second.salary << endl;
		}
	}
}


int main()
{
	//1.����Ա��
	vector<Worker>vWorker;
	CreateWorker(vWorker);

	/*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "������" << it->name << " ���ʣ�" << it->salary << endl;
	}*/

	//Ա������
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

	//Ա����Ϣ��ӡ
	showWorkerGroup(mWorker);

	system("pause");
	return 0;
}


#elif 0
/*
��������
���غ������ò��������࣬������Ϊ��������
��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���

�ص㣺
����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
�������󳬳���ͨ�����ĸ����������������Լ���״̬
�������������Ϊ��������
*/

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test01()
{
	MyAdd add;
	cout << add(10, 10) << endl;
}

//��������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->num = 0;
	}
public:
	void operator()(string x)
	{
		cout << x << endl;
		this->num++;
	}

	int num;//�ڲ��Լ���״̬
};
void test02()
{
	MyPrint print;
	print("hello");
	cout << "���õĴ�����" << print.num << endl;
}

//�������������Ϊ��������
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}

void test03()
{
	MyPrint myprint;
	doPrint(myprint, "hello");
}

#elif 0

/*
����bool���͵ķº�����Ϊν��
���operator��������һ����������ô����һԪν��
���operator��������������������ô������Ԫν��
*/
struct GreaterFive
{
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it != v.end())
	{
		cout << *it << endl;
	}

}

int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0
//��Ԫν��
class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

#elif 1
//�ڽ���������
/*
* plus<T>//�ӷ��º���
* minus<T>--�����º���
* multiplies--�˷��º���
* divides--�����º���
* modulus--ȡģ�º���
* negate--ȡ���º���
* ����ȡ���º�����һԪ���㣬�������Ƕ�Ԫ����
*/

void test01()
{
	negate<int>n;
	cout << n(50) << endl;

	plus<int>p;
	cout << p(50, 30) << endl;

	minus<int>m;
	cout << m(6, 2) << endl;

	multiplies<int>mul;
	cout << mul(2, 3) << endl;


}

void test02()
{
	vector<int>v;
	v.push_back(18);
	v.push_back(29);
	v.push_back(10);
	v.push_back(83);
	v.push_back(1);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test02();
	system("pause");
	return 0;
}

#endif