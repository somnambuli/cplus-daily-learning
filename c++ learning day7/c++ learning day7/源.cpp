#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
using namespace std;

#if 0
//vector插入和删除
void PrintDeque(const deque<int>& D)
{
	for (deque<int>::const_iterator it = D.begin(); it != D.end(); it++)
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

	d1.pop_back();
	PrintDeque(d1);

	d1.insert(d1.begin()+2, 9);
	PrintDeque(d1);

	d1.insert(d1.end(), 2, 1);
	PrintDeque(d1);

	d1.erase(d1.begin());
	PrintDeque(d1);

	d1.clear();
	PrintDeque(d1);


}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//deque数据存取--对deque中的数据的存取操作
void PrintDeque(const deque<int>& D)
{
	for (deque<int>::const_iterator it = D.begin(); it != D.end(); it++)
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

	cout << "容器内第四个数为：" << d1.at(3) << endl;
	cout << "容器内第三个数为：" << d1[2] << endl;
	cout << "容器内第一个数为：" << d1.front() << endl;
	cout << "容器内最后一个数为：" << d1.back() << endl;

}


int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//deque互换容器
void PrintDeque(const deque<int>& D)
{
	for (deque<int>::const_iterator it = D.begin(); it != D.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(50);
	d1.push_back(70);
	d1.push_back(35);
	PrintDeque(d1);

	sort(d1.begin(), d1.end());
	PrintDeque(d1);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//案例--评委打分
/*
* 有5名选手：选手ABCD，10个评委分别对每一名选手打分，去除最高分，去除最低分，取平均分
* 实现步骤：
* 1.创建五名选手，放到vector中
* 2.遍历vecotr容器，取出来每一个选手，执行for循环，可以把十个评委打分存到deque容器中
* 3.sort容器对deque容器中分数排序，去除最高和最低
* 4.deque容器遍历一遍，累加总分
* 5.获取平均分
*/


void test01()
{
	//创建大的vector容器以及小的deque容器
	vector<deque<int>>v;
	deque<int>v1;
	deque<int>v2;
	deque<int>v3;
	deque<int>v4;
	deque<int>v5;
	int sum = 0;
	srand((unsigned)time(NULL));

	//对小容器deque内容赋值
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 41 + 60);
		v2.push_back(rand() % 41 + 60);
		v3.push_back(rand() % 41 + 60);
		v4.push_back(rand() % 41 + 60);
		v5.push_back(rand() % 41 + 60);
	}
	//对大容器vector赋值
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	//对deque容器内的数值进行排序并删除第一和最后一个
	//并对排序后的数组内容求和求平均值 将平均值放到最后一个位置
	for (vector<deque<int>>::iterator it= v.begin(); it != v.end(); it++)
	{
		sort((*it).begin(), (*it).end());
		(*it).pop_back();
		(*it).pop_front();
		sum = 0;
		for (deque<int>::const_iterator dit = (*it).begin(); dit != (*it).end(); dit++)
		{
			sum += *dit;
		}
		(*it).push_back(sum/8);
		cout << sum / 8 << endl;
	}

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//stack容器---先进后出的数据结构（栈）
void test01()
{
	stack<int>s1;
	for (int i = 0; i < 10; i++)
	{
		s1.push(i);
	}
	stack<int>s2(s1);
	stack<int>s3 = s2;
	s1.pop();
	cout << "s1的栈顶元素为：" << s1.top() << endl;
	if (s1.empty() != 1)
	{
		cout << "容器不为空！" << endl;
	}

	cout << "容器的大小为：" << s1.size() << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//queue容器

class Person
{
public:
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}

	string m_name;
	int m_age;
};

void test01()
{
	queue<Person> q;

	//准备数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 999);
	Person p3("猪八戒", 878);
	Person p4("沙僧", 367);

	//向队列中添加元素 入队元素
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "队列大小为:" << q.size() << endl;

	//队列不提供迭代器，更不支持随机访问
	while (!q.empty())
	{
		//输出队头元素
		cout << "队头元素--姓名：" << q.front().m_name << " 年龄 " << q.front().m_age << endl;
		//输出队尾元素
		cout << "队尾元素--姓名：" << q.back().m_name << " 年龄 " << q.back().m_age << endl;

		cout << "---------------------------" << endl;
		q.pop();
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//list容器
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);

	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	list<int>L3(L1);
	printList(L3);

	list<int>L4(4, 30);
	printList(L4);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//list赋值和交换
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);

	list<int>L2;
	L2 = L1;
	printList(L2);

	list<int>L3;
	L3.assign(L1.begin(), L1.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 130);
	printList(L4);

}

void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);

	list<int>L2;
	L2.assign(6, 10);
	printList(L2);

	L1.swap(L2);

	cout << "交换后：" << endl;
	printList(L1);
	printList(L2);

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

#elif 0
//list容器的大小操作
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);

	if (L1.empty())
	{
		cout<<"容器为空！"<<endl;
	}
	else
	{
		cout << "容器不为空！" << endl;
		cout << "容器的大小为：" << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(3);
	printList(L1);

	L1.resize(10);
	printList(L1);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 1
//list插入和删除
//对list容器进行数据的插入和删除

void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	printList(L);

	//尾删
	L.pop_back();
	printList(L);

	//头删
	L.pop_front();
	printList(L);

	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	//删除
	L.erase(it);
	printList(L);

	//移除
	L.push_back(1000);
	L.push_back(1000);
	L.push_back(1000);
	printList(L);
	L.remove(1000);
	printList(L);


	//清空
	L.clear();
	printList(L);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#endif