#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
#include<string>
#include<fstream>

#if 0
//读文件
void test01()
{
	ifstream ifs;
	ifs.open("a.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	//第二种方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	

	//第三种方式
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	//第四种方式
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();
}


#elif 0
//函数模板语法

//交换整形函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换浮点型函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//利用模板提供通用的交换函数
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
	//1.自动类型推导
	MySwap(a,b);

	//2.显示指定类型
	MySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

#elif 0
/*函数模板注意事项
* 1.自动类型推导，必须推导出一致的数据类型T，才可以使用
* 2.模板必须要确定出T的数据类型，才可以使用
*/

//利用模板提供通用的交换函数
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

	mySwap(num1, num2);//正确。可以推导出一致的数据类型
	//mySwap(num1, ch);报错，无法推导出一致的数据类型
	
}

//模板必须要确定出T的数据类型，才可以使用
template<class T>
void myPrint()
{
	cout << "国服马超在此" << endl;
}

void test02()
{
	//myPrint();错误，即使模板里面没有用到T，也必须确定出T的类型才可以调用
	myPrint<int>();
}

#elif 0
//函数模板案例--对不同数据类型数组进行排序
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

//测试字符数组
void test01()
{
	char a[] = "laogebx";
	int length = sizeof(a) / sizeof(a[0]);
	mySort(a, length);
	myPrint(a, length);
}

//测试整型数组
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

//普通函数与函数模板的区别
/*
* 普通函数调用时可以发生自动类型转换（隐式类型转换）
* 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
* 如果利用显示指定类型的方式，可以发生隐式类型转化
*/

//普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}

//使用函数模板时，如果用自动类型推导，不会发生自动类型转换，即隐式转换
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'a';
	//普通函数可以调用成功，会自动发生隐式转换
	myAdd01(a, c);
	//函数模板如果不指定类型，调用失败，不会发生隐式转换
	//myAdd02(b, c);

	myAdd02<int>(a, c);
}


#elif 0
//普通函数与函数模板的调用规则

/*调用规则
* 1、如果函数模板和普通函数都可以实现，优先调用普通函数
* 2、可以通过空模板参数列表来强制调用函数模板
* 3、函数模板可以发生重载
* 4、如果函数模板可以产生更好的匹配，优先调用函数模板
*/

void myPrint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}

template<class T>
void myPrint(T a, T b)
{
	cout << "调用的函数模板" << endl;
}

template<class T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载的函数模板" << endl;
}

void test()
{
	int a = 10;
	int b = 20;
	int c = 10;
	myPrint(a, b);

	//可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a, b);
	myPrint<>(a, b,c);
	//如果函数模板可以产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

#elif 0
//模板的局限性
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

//此时当传入自定义数据类型时，函数模板无法调用
//具体化优先于常规模板
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
	Person p1("张三", 13);
	Person p2("李四", 15);
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
//类模板语法
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
	Person<string, int>p("马超", 15);
	p.showPerson();
}


#elif 0

//类模板与函数模板区别
/*
* 1.类模板没有自动类型推导的使用方式
* 2.类模板在模板参数列表中可以有默认参数
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
	Person<string>p("猪八戒", 999);
	p.showPerson();
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 1
//类模板中成员函数创建实机
/*
* 普通类中的成员函数一开始就可以创建
* 类模板中的成员函数在调用时才创建
*/

class Person1
{
public:
	void func1()
	{
		cout << "Person1中的func函数调用" << endl;
	}
};

class Person2
{
public:
	void func2()
	{
		cout << "Person2中的func函数调用" << endl;
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
	a.function2();//写出来没有语法错误，但编译阶段会报错
}
#endif