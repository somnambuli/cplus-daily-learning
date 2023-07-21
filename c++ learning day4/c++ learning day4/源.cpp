#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

#if 0

//��ģ���������������

//��ģ��
template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		m_Name = name;
		m_Age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}
public:
	T1 m_Name;
	T2 m_Age;
};

//���ֱ��дPerson& p�������ᱨ���޷�ʶ����ģ���еĲ���
//1��ָ�����������
void PrintPerson1(Person<string,int>& p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("������", 17);
	PrintPerson1(p);
}


//2.����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1,T2>& p)
{
	cout << "T1������Ϊ" << typeid(T1).name() << endl;
	cout << "T2������Ϊ" << typeid(T2).name() << endl;
	p.showPerson();
}
void test02()
{
	Person<string, int>p("��", 23);
	printPerson2(p);
}

//3.������ģ�廯
template<class T>
void printPerson3(T& p)
{
	cout << "T������Ϊ" << typeid(T).name() << endl;
	p.showPerson();

}

void test03()
{
	Person<string, int>p("����", 35);
	printPerson3(p);
}

int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}

#elif 0
//��ģ����̳�
/*������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ��������T������
* �����ָ�����������޷�����������ڴ�
* ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
*/

template<class T>
class Base
{
	T m;
};

class Son :public Base<int>
{

};

void test01()
{
	Son c;
}

//��ģ��̳���ģ�壬������T2ָ�������е�T����
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1��������" << typeid(T1).name() << endl;
		cout << "T2��������" << typeid(T2).name() << endl;
	}
};

void test02()
{
	Son2<int, char>child1;
}

#elif 0
//��ģ���Ա��������ʵ��
template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);

	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};

template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	m_Name = name;
	m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "������" << this->m_Name << " ���䣺 " << this->m_Age << endl;
}


void test()
{
	Person<string, int>p("������", 999);
	p.showPerson();
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 0
//��ģ����ļ���д
/*
* ���⣺��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
* �����ʽ1��ֱ�Ӱ���.cppԴ�ļ�
* �����ʽ2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��
*/

#elif 0
//��ģ�������Ԫ���������ں�����ʵ��


//2.ȫ�ֺ��������Ԫ������ʵ��--��������ģ���������·���������ģ�嶨�壬������Ԫ
template<class T1, class T2>class Person;

template<class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "����ʵ��" << endl;
}

template<class T1,class T2>
class Person
{
	//ȫ�ֺ�������ʵ��
	friend void showPerson1(Person<T1,T2>&p)
	{
		cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
		cout << "ȫ�ֺ�������ʵ��" << endl;
	}

	//ȫ�ֺ��������Ԫ������ʵ��
	friend void printPerson2<>(Person<T1, T2>& p);

public:
	Person(T1 name, T2 age);

private:
	T1 m_Name;
	T2 m_Age;
};


template<class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->m_Age = age;
	this->m_Name = name;
}


void test01()
{
	Person<string, int>p("����", 13);
	showPerson1(p);

}

void test02()
{
	Person<string, int>p2("����", 23);
	printPerson2(p2);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

#elif 1
#include"myArray.hpp"
//��ģ��İ���

void PrintIntArr(MyArray<int>& p)
{
	for (int i = 0; i < p.getSize(); i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

//����������������
void test01()
{
	MyArray<int>m_arr1(10);
	for (int i = 0; i < 10; i++)
	{
		m_arr1.Push_back(i);
	}

	cout << "int���͵�MyArry�����ӡ" << endl;
	PrintIntArr(m_arr1);
	cout << "m_arr1������" << m_arr1.getCapaticy() << endl;
	cout << "m_arr1�Ĵ�С" << m_arr1.getSize() << endl;

	cout << "----------------------------------------" << endl;
	//���Կ�������
	MyArray<int>m_arr2(m_arr1);
	m_arr2.Pop_back();
	PrintIntArr(m_arr2);
	cout << "m_arr2������" << m_arr2.getCapaticy() << endl;
	cout << "m_arr2�Ĵ�С" << m_arr2.getSize() << endl;


}

//�����Զ�����������
class Person
{
public:
	Person()
	{

	}

	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};


void PrintPersonArr(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "������ " << arr[i].m_Name << "���䣺 " << arr[i].m_Age << endl;
	}

	cout << endl;
}

void test02()
{
	MyArray<Person>arr3(5);
	Person p1("�������", 23);
	Person p2("���Ŷ�", 13);
	Person p3("槼�", 19);
	Person p4("��ɲ���", 25);

	arr3.Push_back(p1);
	arr3.Push_back(p2);
	arr3.Push_back(p3);
	arr3.Push_back(p4);
	PrintPersonArr(arr3);
	cout << "arr3�Ĵ�С" << arr3.getSize() << endl;
	cout << "arr3������" << arr3.getCapaticy() << endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

#endif
