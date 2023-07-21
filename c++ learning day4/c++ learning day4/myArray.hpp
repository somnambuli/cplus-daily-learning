#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<iostream>
#include<string>
using namespace std;


template<class T>
class MyArray
{
public:
	//构造函数
	MyArray(int cap)
	{
		this->m_Capacity = cap;
		this->m_Size = 0;
		this->pAddress = new T[cap];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//如果属性中有堆区开辟的数据，则必须重载=运算符，进行深拷贝操作
	MyArray& operator=(const MyArray& arr)
	{

		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;

		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//重载[]
	T operator[](int index)
	{
		return this->pAddress[index];
	}

	//尾插法
	void Push_back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "内存已满" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			cout << "容器为空" << endl;
		}
		this->m_Size--;
	}

	//获取数组容量
	int getCapaticy()
	{
		return this->m_Capacity;
	}

	//获取数组大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

	}
private:
	T* pAddress;//指向一个堆空间，这个空间用来存放真正的数据
	int m_Capacity;//容量
	int m_Size;//现在存储的大小
};