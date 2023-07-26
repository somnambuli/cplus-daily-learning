#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<set>
using namespace std;

#if 0

//list数据存取
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	//cout<<L1.at(0)<<endl;//错误 不支持at访问数据
	//cout<<L1[0]<<endl;//错误 不支持[]方式访问数据
	cout << "第一个元素为：" << L1.front() << endl;
	cout << "最后一个元素为：" << L1.back() << endl;

	//list容器的迭代器是双向迭代器，不支持随机访问
	list<int>::iterator it = L1.begin();
	//it = it + 1;错误 list的迭代器不支持随机访问 即使是+1
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//list反转和排序--将容器中的元素反转，以及将容器中的数据进行排序

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

	//反转容器的元素
	L.reverse();
	printList(L);

	//排序
	L.sort();//默认的排序规则 从小到大
	printList(L);

	L.sort(myCompare);//指定规则，从大到小
	printList(L);
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//排序案例
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
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << " 身高：" << it->m_high << endl;
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
	Person p1("rg牛", 35, 190);
	Person p2("rg海牛", 16, 240);
	Person p3("mg红异端", 35, 160);
	Person p4("8802强袭自由", 28, 235);
	Person p5("6637独角兽", 16, 176);
	Person p6("6650自由2.0", 26, 210);
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
//set/multiset容器
//所有元素都会在插入时自动被排序--属于关联式容器，底层结构是用二叉树实现
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//构造和赋值
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(40);
	s1.insert(20);

	printSet(s1);

	//拷贝构造
	set<int>s2(s1);
	printSet(s2);

	//赋值
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
//set大小和交换---统计set容器大小及交换set容器
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
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空！容器的大小为：" << s1.size() << endl;
	}

	set<int>s2;
	s2.insert(80);
	s2.insert(40);
	s2.insert(54);
	s2.insert(20);

	cout << "交换前：" << endl;
	printSet(s1);
	printSet(s2);

	s1.swap(s2);
	cout << "交换后：" << endl;
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
//set容器进行插入数据和删除数据
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

	//删除
	s1.erase(s1.begin());
	printSet(s1);

	//删除
	s1.erase(30);
	printSet(s1);

	//清空
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
//set查找和统计
//对set容器进行查找数据以及统计数据
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int>::iterator pos = s1.find(30);
	//查找
	if (pos != s1.end())
	{
		cout << "找到了元素：" << *pos << endl;
	}
	else
		cout << "元素未找到！" << endl;

	//统计
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
//set和multiset区别
/*
set不可以插入重复数据，而multiset可以
set插入数据的同时会返回插入结果，表示插入是否成功
multiset不会检测数据，因此可以插入重复数据
*/


void test01()
{
	set<int>s1;
	pair<set<int>::iterator, bool>ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第一个数据插入成功" << endl;
	}
	else
	{
		cout << "第一个数据插入失败" << endl;
	}

	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第二个数据插入成功" << endl;
	}
	else
	{
		cout << "第二个数据插入失败" << endl;
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
//pair对组创建--成对出现的数据，利用对组可以返回两个数据
void test01()
{
	pair<string, int>p1(string("马信号"), 32);
	cout << "姓名：" << p1.first << " 年龄：" << p1.second << endl;
	pair<string, int>p2 = make_pair("安其拉", 15);
	cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0
//set容器默认排序规则从小到大，掌握如何改变排序规则
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

//内置数据类型
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

//自定义数据类型
void test02()
{
	Person p1("刘备", 35);
	Person p2("关羽", 24);
	Person p3("张飞", 32);
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