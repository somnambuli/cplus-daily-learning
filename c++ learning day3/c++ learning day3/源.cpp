#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#include<string>
#include<fstream>

#if 0
//���ļ�
void test01()
{
	ifstream ifs;
	ifs.open("a.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��һ�ַ�ʽ
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//�ڶ��ַ�ʽ
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	

	//�����ַ�ʽ
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	//�����ַ�ʽ
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();
}


#elif 0
//����ģ���﷨

//�������κ���
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//���������ͺ���
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ���ṩͨ�õĽ�������
template<class T>
void MySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test()
{
	int a = 10;
	int b = 20;
	//1.�Զ������Ƶ�
	MySwap(a,b);

	//2.��ʾָ������
	MySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

#elif 0
/*����ģ��ע������
* 1.�Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
* 2.ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
*/

//����ģ���ṩͨ�õĽ�������
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int num1 = 10;
	int num2 = 20;
	char ch = 'a';

	mySwap(num1, num2);//��ȷ�������Ƶ���һ�µ���������
	//mySwap(num1, ch);�����޷��Ƶ���һ�µ���������
	
}

//ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void myPrint()
{
	cout << "�������ڴ�" << endl;
}

void test02()
{
	//myPrint();���󣬼�ʹģ������û���õ�T��Ҳ����ȷ����T�����Ͳſ��Ե���
	myPrint<int>();
}

#elif 0
//����ģ�尸��--�Բ�ͬ�������������������
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


template<class T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] > arr[max]) max = j;
		}

		if (max != i)
			mySwap(arr[i], arr[max]);

	}
}

//�����ַ�����
void test01()
{
	char a[] = "laogebx";
	int length = sizeof(a) / sizeof(a[0]);
	mySort(a, length);
	myPrint(a, length);
}

//������������
void test02()
{
	int b[] = { 1,3,2,6,8,4,0 };
	int length = sizeof(b) / sizeof(b[0]);
	mySort(b, length);
	myPrint(b, length);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

#elif 0

//��ͨ�����뺯��ģ�������
/*
* ��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
* ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
* ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
*/

//��ͨ����
int myAdd01(int a, int b)
{
	return a + b;
}

template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}

//ʹ�ú���ģ��ʱ��������Զ������Ƶ������ᷢ���Զ�����ת��������ʽת��
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'a';
	//��ͨ�������Ե��óɹ������Զ�������ʽת��
	myAdd01(a, c);
	//����ģ�������ָ�����ͣ�����ʧ�ܣ����ᷢ����ʽת��
	//myAdd02(b, c);

	myAdd02<int>(a, c);
}


#elif 0
//��ͨ�����뺯��ģ��ĵ��ù���

/*���ù���
* 1���������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
* 2������ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
* 3������ģ����Է�������
* 4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
*/

void myPrint(int a, int b)
{
	cout << "���õ���ͨ����" << endl;
}

template<class T>
void myPrint(T a, T b)
{
	cout << "���õĺ���ģ��" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "�������صĺ���ģ��" << endl;
}

void test()
{
	int a = 10;
	int b = 20;
	int c = 10;
	myPrint(a, b);

	//����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
	myPrint<>(a, b);
	myPrint<>(a, b,c);
	//�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

#elif 0
//ģ��ľ�����
class Person
{
public:
	Person(string name, int age)
	{
		m_age = age;
		m_name = name;
	}
public:
	int m_age;
	string m_name;
};

//��ʱ�������Զ�����������ʱ������ģ���޷�����
//���廯�����ڳ���ģ��
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}

template<>
bool myCompare(Person& a, Person& b)
{
	if (a.m_age == b.m_age && a.m_name == b.m_name)
		return true;
	else
		return false;
}

void test()
{
	int num1 = 10;
	int num2 = 20;
	bool ceshi = myCompare(num1, num2);
	cout << ceshi << endl;
	Person p1("����", 13);
	Person p2("����", 15);
	ceshi = myCompare(p1, p2);
	cout << ceshi << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}


#elif 0
//��ģ���﷨
template<class nametype,class agetype>
class Person
{
public:
	Person(nametype name, agetype age)
	{
		m_name = name;
		m_age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->m_name << " age: " << this->m_age << endl;
	}

public:
	nametype m_name;
	agetype m_age;
};

void test01()
{
	Person<string, int>p("��", 15);
	p.showPerson();
}


#elif 0

//��ģ���뺯��ģ������
/*
* 1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
* 2.��ģ����ģ������б��п�����Ĭ�ϲ���
*/

template<class NameType,class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}
public:
	NameType m_Name;
	AgeType m_Age;
};

void test()
{
	Person<string>p("��˽�", 999);
	p.showPerson();
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 1
//��ģ���г�Ա��������ʵ��
/*
* ��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
* ��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
*/

class Person1
{
public:
	void func1()
	{
		cout << "Person1�е�func��������" << endl;
	}
};

class Person2
{
public:
	void func2()
	{
		cout << "Person2�е�func��������" << endl;
	}
};

template<class T>
class MyClass
{
public:
	void function1()
	{
		obj.func1();
	}

	void function2()
	{
		obj.func2();
	}
	
public:
	T obj;
};

void test()
{
	MyClass<Person1>a;
	a.function1();
	a.function2();//д����û���﷨���󣬵�����׶λᱨ��
}
#endif