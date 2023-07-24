#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<iostream>
#include<string>
using namespace std;


template<class T>
class MyArray
{
public:
	//���캯��
	MyArray(int cap)
	{
		this->m_Capacity = cap;
		this->m_Size = 0;
		this->pAddress = new T[cap];
	}

	//��������
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

	//����������ж������ٵ����ݣ����������=������������������
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

	//����[]
	T operator[](int index)
	{
		return this->pAddress[index];
	}

	//β�巨
	void Push_back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "�ڴ�����" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			cout << "����Ϊ��" << endl;
		}
		this->m_Size--;
	}

	//��ȡ��������
	int getCapaticy()
	{
		return this->m_Capacity;
	}

	//��ȡ�����С
	int getSize()
	{
		return this->m_Size;
	}

	//��������
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
	T* pAddress;//ָ��һ���ѿռ䣬����ռ������������������
	int m_Capacity;//����
	int m_Size;//���ڴ洢�Ĵ�С
};