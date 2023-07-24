#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;



#if 0
//vector容器
//vector数据结构与数组非常类似，也称为单端数组
//不同之处在于数组是静态空间，而vector可以动态扩展
//并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

void PrintVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

//vector构造函数
void test01()
{
	//无参构造
	vector<int>v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);

	//将v[begin(),end()]区间中的元素拷贝给本身
	vector<int>v2(v1.begin(), v1.end());
	PrintVector(v2);

	//构造函数将n个elem拷贝给本身
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

//vector容器赋值操作
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
//对vector的容量和大小操作
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

	cout << "v1的容量为 " << v1.capacity() << endl;
	cout << "v1中元素的个数为" << v1.size() << endl;

	v1.resize(7);
	cout << "v1的容量为 " << v1.capacity() << endl;
	PrintVector(v1);

	v1.resize(10, 3);
	cout << "v1的容量为 " << v1.capacity() << endl;
	PrintVector(v1);
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//vector插入和删除
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
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	PrintVector(v1);

	//尾删
	v1.pop_back();
	PrintVector(v1);

	//插入
	v1.insert(v1.begin(), 1);
	PrintVector(v1);

	//插入
	v1.insert(v1.end(), 3, 2);
	PrintVector(v1);

	//删除
	v1.erase(++v1.begin());
	PrintVector(v1);

	//删除
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
//vector数据存取

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
	cout << "v1的第四个元素为" << a << endl;

	cout << "v1的第三个元素为" << v1[2] << endl;

	cout << "v1的第一个元素为" << v1.front() << endl;
	cout << "v1的最后一个元素为" << v1.back() << endl;


}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//vector互换容器
//实现两个容器内元素进行互换
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
	cout << "互换后：" << endl;
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

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//巧用swap收缩内存
	vector<int>(v).swap(v);//开辟一个匿名对象，该行执行后匿名对象被释放
	cout << "收缩后v的容量为：" << v.capacity() << endl;
	cout << "收缩后v的大小为：" << v.size() << endl;


}

int main()
{
	//test01();
	test02();
	system("pause");
;	return 0;
}

#elif 0
//预留空间
//减少vector在动态扩展容量时的拓展次数

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

//deque容器构造
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
	//默认构造
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	PrintDeque(d1);

	//拷贝构造
	deque<int>d2(d1.begin(), d1.end());
	PrintDeque(d2);

	//构造函数将n个elem拷贝给本身
	deque<int>d3(4, 6);
	PrintDeque(d3);

	//拷贝构造函数
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
//deque大小操作
//对deque容器的大小进行操作

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
		cout << "容器不为空！" << endl;
	}
	else
	{
		cout << "容器为空" << endl;
	}

	cout << "容器的大小为：" << d1.size() << endl;
	d1.resize(3);
	cout << "容器的大小为：" << d1.size() << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}


#endif