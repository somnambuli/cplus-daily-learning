#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<set>
using namespace std;

#if 0

//list���ݴ�ȡ
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	//cout<<L1.at(0)<<endl;//���� ��֧��at��������
	//cout<<L1[0]<<endl;//���� ��֧��[]��ʽ��������
	cout << "��һ��Ԫ��Ϊ��" << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << L1.back() << endl;

	//list�����ĵ�������˫�����������֧���������
	list<int>::iterator it = L1.begin();
	//it = it + 1;���� list�ĵ�������֧��������� ��ʹ��+1
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//list��ת������--�������е�Ԫ�ط�ת���Լ��������е����ݽ�������

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

bool myCompare(int val1, int val2)
{
	return val1 > val2;
}

void test01()
{
	list<int>L;
	L.push_back(90);
	L.push_back(10);
	L.push_back(34);
	L.push_back(12);
	L.push_back(80);
	printList(L);

	//��ת������Ԫ��
	L.reverse();
	printList(L);

	//����
	L.sort();//Ĭ�ϵ�������� ��С����
	printList(L);

	L.sort(myCompare);//ָ�����򣬴Ӵ�С
	printList(L);
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//������
class Person
{
public:
	Person(string name, int age, int high)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_high = high;
	}
public:
	string m_name;
	int m_age;
	int m_high;
};

void printPerson(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������" << it->m_name << " ���䣺" << it->m_age << " ��ߣ�" << it->m_high << endl;
	}
	cout << "----------------------" << endl;
}

bool mySort(Person& per1, Person& per2)
{
	if (per1.m_age == per2.m_age)
	{
		return per1.m_high > per2.m_high;
	}
	else
	{
		return per1.m_age < per2.m_age;
	}
}

void test01()
{
	list<Person>L;
	Person p1("rgţ", 35, 190);
	Person p2("rg��ţ", 16, 240);
	Person p3("mg�����", 35, 160);
	Person p4("8802ǿϮ����", 28, 235);
	Person p5("6637������", 16, 176);
	Person p6("6650����2.0", 26, 210);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	printPerson(L);

	L.sort(mySort);
	printPerson(L);
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//set/multiset����
//����Ԫ�ض����ڲ���ʱ�Զ�������--���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//����͸�ֵ
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);
	s1.insert(20);

	printSet(s1);

	//��������
	set<int>s2(s1);
	printSet(s2);

	//��ֵ
	set<int>s3;
	s3 = s1;
	printSet(s3);
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//set��С�ͽ���---ͳ��set������С������set����
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(24);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ�գ������Ĵ�СΪ��" << s1.size() << endl;
	}

	set<int>s2;
	s2.insert(80);
	s2.insert(40);
	s2.insert(54);
	s2.insert(20);

	cout << "����ǰ��" << endl;
	printSet(s1);
	printSet(s2);

	s1.swap(s2);
	cout << "������" << endl;
	printSet(s1);
	printSet(s2);
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//set�������в������ݺ�ɾ������
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(24);
	s1.insert(40);
	printSet(s1);

	//ɾ��
	s1.erase(s1.begin());
	printSet(s1);

	//ɾ��
	s1.erase(30);
	printSet(s1);

	//���
	s1.clear();
	printSet(s1);
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//set���Һ�ͳ��
//��set�������в��������Լ�ͳ������
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int>::iterator pos = s1.find(30);
	//����
	if (pos != s1.end())
	{
		cout << "�ҵ���Ԫ�أ�" << *pos << endl;
	}
	else
		cout << "Ԫ��δ�ҵ���" << endl;

	//ͳ��
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//set��multiset����
/*
set�����Բ����ظ����ݣ���multiset����
set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
multiset���������ݣ���˿��Բ����ظ�����
*/


void test01()
{
	set<int>s1;
	pair<set<int>::iterator, bool>ret = s1.insert(10);
	if (ret.second)
	{
		cout << "��һ�����ݲ���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�����ݲ���ʧ��" << endl;
	}

	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "�ڶ������ݲ���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ������ݲ���ʧ��" << endl;
	}

	//multiset
	multiset<int>s2;
	s2.insert(10);
	s2.insert(10);
	for (multiset<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0
//pair���鴴��--�ɶԳ��ֵ����ݣ����ö�����Է�����������
void test01()
{
	pair<string, int>p1(string("���ź�"), 32);
	cout << "������" << p1.first << " ���䣺" << p1.second << endl;
	pair<string, int>p2 = make_pair("������", 15);
	cout << "������" << p2.first << " ���䣺" << p2.second << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0
//set����Ĭ����������С����������θı��������
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class MyCompare
{
public:
	bool operator()(int val1, int val2)const
	{
		return val1 > val2;
	}
};

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;

	}
public:
	string m_name;
	int m_age;
};

class PersonCompare
{
public:
	bool operator()(const Person& p1,const Person& p2)const
	{
		return p1.m_age > p2.m_age;
	}
};

//������������
void test01()
{
	set<int>s1;
	s1.insert(20);
	s1.insert(10);
	s1.insert(50);
	s1.insert(60);
	s1.insert(30);
	printSet(s1);

	set<int, MyCompare>s2;
	s2.insert(37);
	s2.insert(67);
	s2.insert(34);
	s2.insert(77);
	s2.insert(92);

	for (set<int, MyCompare>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//�Զ�����������
void test02()
{
	Person p1("����", 35);
	Person p2("����", 24);
	Person p3("�ŷ�", 32);
	set<Person,PersonCompare>s1;
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);

	for (set<Person, PersonCompare>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << it->m_name << " " << it->m_age << endl;
	}
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}




#endif