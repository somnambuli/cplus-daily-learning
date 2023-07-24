#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;



#if 0
//vector����
//vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������
//��֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ
//��������ԭ�ռ�֮�������¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�

void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

//vector���캯��
void test01()
{
	//�޲ι���
	vector<int>v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	//��v[begin(),end()]�����е�Ԫ�ؿ���������
	vector<int>v2(v1.begin(), v1.end());
	PrintVector(v2);

	//���캯����n��elem����������
	vector<int>v3(5, 1);
	PrintVector(v3);

	vector<int>v4(v1);
	PrintVector(v4);


}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0

//vector������ֵ����
void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	vector<int>v2 = v1;
	PrintVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	PrintVector(v3);

	vector<int>v4;
	v4.assign(5, 100);
	PrintVector(v4);

}
int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//��vector�������ʹ�С����
void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	cout << "v1������Ϊ " << v1.capacity() << endl;
	cout << "v1��Ԫ�صĸ���Ϊ" << v1.size() << endl;

	v1.resize(7);
	cout << "v1������Ϊ " << v1.capacity() << endl;
	PrintVector(v1);

	v1.resize(10, 3);
	cout << "v1������Ϊ " << v1.capacity() << endl;
	PrintVector(v1);
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//vector�����ɾ��
void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	PrintVector(v1);

	//βɾ
	v1.pop_back();
	PrintVector(v1);

	//����
	v1.insert(v1.begin(), 1);
	PrintVector(v1);

	//����
	v1.insert(v1.end(), 3, 2);
	PrintVector(v1);

	//ɾ��
	v1.erase(++v1.begin());
	PrintVector(v1);

	//ɾ��
	v1.clear();
	PrintVector(v1);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//vector���ݴ�ȡ

void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	int a = v1.at(3);
	cout << "v1�ĵ��ĸ�Ԫ��Ϊ" << a << endl;

	cout << "v1�ĵ�����Ԫ��Ϊ" << v1[2] << endl;

	cout << "v1�ĵ�һ��Ԫ��Ϊ" << v1.front() << endl;
	cout << "v1�����һ��Ԫ��Ϊ" << v1.back() << endl;


}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//vector��������
//ʵ������������Ԫ�ؽ��л���
void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);

	}

	vector<int>v2;
	for (int i = 10; i>0; i--)
	{
		v2.push_back(i);
	}
	PrintVector(v1);
	PrintVector(v2);

	v1.swap(v2);
	cout << "������" << endl;
	PrintVector(v1);
	PrintVector(v2);

}

void test02()
{
	vector<int>v;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
	}

	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	v.resize(3);
	cout << "v������Ϊ��" << v.capacity() << endl;
	cout << "v�Ĵ�СΪ��" << v.size() << endl;

	//����swap�����ڴ�
	vector<int>(v).swap(v);//����һ���������󣬸���ִ�к����������ͷ�
	cout << "������v������Ϊ��" << v.capacity() << endl;
	cout << "������v�Ĵ�СΪ��" << v.size() << endl;


}

int main()
{
	//test01();
	test02();
	system("pause");
;	return 0;
}

#elif 0
//Ԥ���ռ�
//����vector�ڶ�̬��չ����ʱ����չ����

void test01()
{
	vector<int>v;
	v.reserve(1000);
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0

//deque��������
void PrintDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
}

void test01()
{
	//Ĭ�Ϲ���
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);

	//��������
	deque<int>d2(d1.begin(), d1.end());
	PrintDeque(d2);

	//���캯����n��elem����������
	deque<int>d3(4, 6);
	PrintDeque(d3);

	//�������캯��
	deque<int>d4(d3);
	PrintDeque(d4);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0

void PrintDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
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

	deque<int>d2;
	d2 = d1;
	PrintDeque(d2);

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	PrintDeque(d3);

	deque<int>d4;
	d4.assign(5, 7);
	PrintDeque(d4);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 1
//deque��С����
//��deque�����Ĵ�С���в���

void PrintDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
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

	if (d1.empty() != 1)
	{
		cout << "������Ϊ�գ�" << endl;
	}
	else
	{
		cout << "����Ϊ��" << endl;
	}

	cout << "�����Ĵ�СΪ��" << d1.size() << endl;
	d1.resize(3);
	cout << "�����Ĵ�СΪ��" << d1.size() << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}


#endif