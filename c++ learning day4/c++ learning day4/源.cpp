#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

#if 0

//类模板对象做函数参数

//类模板
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

//如果直接写Person& p编译器会报错，无法识别类模板中的参数
//1、指定传入的类型
void PrintPerson1(Person<string,int>& p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("孙尚香", 17);
	PrintPerson1(p);
}


//2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>& p)
{
	cout << "T1的类型为" << typeid(T1).name() << endl;
	cout << "T2的类型为" << typeid(T2).name() << endl;
	p.showPerson();
}
void test02()
{
	Person<string, int>p("镜", 23);
	printPerson2(p);
}

//3.整个类模板化
template<class T>
void printPerson3(T& p)
{
	cout << "T的类型为" << typeid(T).name() << endl;
	p.showPerson();

}

void test03()
{
	Person<string, int>p("宫本", 35);
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
//类模板与继承
/*当子类继承的父类是一个类模板时，子类在声明的时候，要指出父类中T的类型
* 如果不指定，编译器无法给子类分配内存
* 如果想灵活指定出父类中T的类型，子类也需变为类模板
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

//类模板继承类模板，可以用T2指定父类中的T类型
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1的类型是" << typeid(T1).name() << endl;
		cout << "T2的类型是" << typeid(T2).name() << endl;
	}
};

void test02()
{
	Son2<int, char>child1;
}

#elif 0
//类模板成员函数类外实现
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
	cout << "姓名：" << this->m_Name << " 年龄： " << this->m_Age << endl;
}


void test()
{
	Person<string, int>p("奥特曼", 999);
	p.showPerson();
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 0
//类模板分文件编写
/*
* 问题：类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
* 解决方式1：直接包含.cpp源文件
* 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
*/

#elif 0
//类模板配合友元函数的类内和类外实现


//2.全局函数配合友元，类外实现--先做函数模板声明，下方再做函数模板定义，再做友元
template<class T1, class T2>class Person;

template<class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "类外实现" << endl;
}

template<class T1,class T2>
class Person
{
	//全局函数类内实现
	friend void showPerson1(Person<T1,T2>&p)
	{
		cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
		cout << "全局函数类内实现" << endl;
	}

	//全局函数配合友元，类外实现
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
	Person<string, int>p("张三", 13);
	showPerson1(p);

}

void test02()
{
	Person<string, int>p2("李四", 23);
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
//类模板的案例

void PrintIntArr(MyArray<int>& p)
{
	for (int i = 0; i < p.getSize(); i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

//测试内置数据类型
void test01()
{
	MyArray<int>m_arr1(10);
	for (int i = 0; i < 10; i++)
	{
		m_arr1.Push_back(i);
	}

	cout << "int类型的MyArry数组打印" << endl;
	PrintIntArr(m_arr1);
	cout << "m_arr1的容量" << m_arr1.getCapaticy() << endl;
	cout << "m_arr1的大小" << m_arr1.getSize() << endl;

	cout << "----------------------------------------" << endl;
	//测试拷贝构造
	MyArray<int>m_arr2(m_arr1);
	m_arr2.Pop_back();
	PrintIntArr(m_arr2);
	cout << "m_arr2的容量" << m_arr2.getCapaticy() << endl;
	cout << "m_arr2的大小" << m_arr2.getSize() << endl;


}

//测试自定义数据类型
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
		cout << "姓名： " << arr[i].m_Name << "年龄： " << arr[i].m_Age << endl;
	}

	cout << endl;
}

void test02()
{
	MyArray<Person>arr3(5);
	Person p1("宫本武藏", 23);
	Person p2("阿古朵", 13);
	Person p3("妲己", 19);
	Person p4("马可波罗", 25);

	arr3.Push_back(p1);
	arr3.Push_back(p2);
	arr3.Push_back(p3);
	arr3.Push_back(p4);
	PrintPersonArr(arr3);
	cout << "arr3的大小" << arr3.getSize() << endl;
	cout << "arr3的容量" << arr3.getCapaticy() << endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

#endif
