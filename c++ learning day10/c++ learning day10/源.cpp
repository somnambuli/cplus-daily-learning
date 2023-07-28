#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<numeric>
using namespace std;

#if 0

/*
逻辑仿函数--实现逻辑运算
bool logical_and 逻辑与
bool logical_or 逻辑或
bool logical_not 逻辑非
*/

void test01()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;

	vector<bool>v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//常用算法
//常用遍历算法

//普通函数
void print(int val)
{
	cout << val << " ";
}

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	//for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//transform--搬运容器到另一个容器中
class mytransform
{
public:
	int operator()(int val)
	{
		return val;
	}
};

class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), mytransform());
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint());
	cout << endl;
}

class Person
{
public:
	Person()
	{

	}
	Person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}
public:
	int m_age;
	string m_name;
};


class PersonTransform
{
public:
	Person operator()(Person p)
	{
		return p;
	}
};
void test02()
{
	vector<Person>v1;
	string s1 = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string s2 = "观众";
		Person person(s2+s1[i], i);
		v1.push_back(person);
	}

	vector<Person>v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), PersonTransform());
	for (vector<Person>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << it->m_name << endl;
	}
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

#elif 0
//常用查找算法--掌握常用的查找算法
//find--查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了！:" << *it << endl;
	}
}

class Person
{
public:
	Person()
	{

	}
	Person(int age, int high)
	{
		this->age = age;
		this->high = high;
	}

	bool operator==(const Person& p)
	{
		if (this->age == p.age && this->high == p.high)
		{
			return true;
		}
		else
			return false;
	}
	int age;
	int high;
};
void test02()
{
	vector<Person>v1;
	Person p1(10, 20);
	Person p2(23, 48);
	Person p3(25, 73);
	Person p4(14, 87);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	Person pp(25, 73);
	vector<Person>::iterator it = find(v1.begin(), v1.end(), pp);
	if (it != v1.end())
	{
		cout << "找到了：" << " 姓名：" << it->age << " 身高：" << it->high << endl;
	}

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

#elif 0

//find_if
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg开始迭代器
//end结束迭代器
//_Pred函数或者谓词（返回bool类型的仿函数）


//内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "没找到！" << endl;
	}
	else
	{
		cout << "找到大于5的数字：" << *it << endl;
	}
}

//自定义数据类型
class Person
{
public:
	Person(int age, int high)
	{
		m_age = age;
		m_high = high;
	}

	int m_age;
	int m_high;
};

class GreaterErshi
{
public:
	bool operator()(Person& p)
	{
		if (p.m_age > 20)
			return true;
		else
			return false;
	}
};

void test02()
{
	vector<Person>v1;
	Person p1(10, 20);
	Person p2(20, 30);
	Person p3(30, 40);
	Person p4(40, 50);
	Person p5(50, 60);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	vector<Person>::iterator it = find_if(v1.begin(), v1.end(), GreaterErshi());
	if (it != v1.end())
	{
		cout << "找到了！年龄为：" << it->m_age << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

#elif 0
//adjacent_find--查找相邻重复元素
//查找相邻重复元素，返回相邻元素的第一个位置的迭代器
//beg开始迭代器
//end结束迭代器

void test01()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
		cout << "相邻的重复元素为：" << *it << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//bool binary_search--查找指定的元素，查到返回true否则false
//二分查找法--只有在有序容器中才可以使用
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	bool ret = binary_search(v.begin(), v.end(), 3);
	if (ret)
		cout << "找到了" << endl;
	else
		cout << "未找到" << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//count--统计元素出现次数

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	bool operator==(const Person& p)
	{
		if (this->m_age == p.m_age)
			return true;
		else
			return false;
	}

	int m_age;
	string m_name;
};


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int num = count(v.begin(), v.end(), 2);
	cout << "元素出现的次数为：" << num << endl;
}

void test02()
{
	vector<Person>v;
	Person p1("张三", 13);
	Person p2("刘备", 12);
	Person p3("孙悟空", 14);
	Person p4("统计", 13);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("王五", 13);

	int num = count(v.begin(), v.end(), pp);
	cout << "元素出现的次数为：" << num << endl;
}


int main()
{
	test02();
	system("pause");
	return 0;
}

#elif 0
//count_if按条件统计元素个数
//count_if按条件统计元素出现次数

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	int m_age;
	string m_name;
};

class Greatershi
{
public:
	bool operator()(const Person& p)
	{
		return p.m_age > 20;
	}
};

int MyPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<Person>v;
	Person p1("张三", 13);
	Person p2("刘备", 23);
	Person p3("孙悟空", 14);
	Person p4("统计", 13);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	for_each(v.begin(), v.end(), MyPrint);

	int num = count_if(v.begin(), v.end(), Greatershi());
	cout << "大于20的个数为：" << num << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//常用排序算法--sort

void myprint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	//sort默认从小到大排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myprint);

	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), myprint);

}

int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0
//random_shuffle--洗牌 指定范围内的元素随机调整次序
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	srand((unsigned int) time(NULL));
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//merge--两个容器元素合并，并存储到另一容器中
//两个容器必须是有序的

class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myprint());
	cout << endl;

	vector<int>vtarger;
	//目标需提前开辟空间
	vtarger.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarger.begin());
	for_each(vtarger.begin(), vtarger.end(), myprint());
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//reverse--将容器内元素进行反转
class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//常用拷贝和替换算法
//copy--拷贝操作
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//replace--将容器内指定范围的旧元素修改为新元素
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(5);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	replace(v.begin(), v.end(), 5, 10);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//replace_if--将区间内满足条件的元素，替换成指定元素
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

class MyReplace
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), MyPrint());
	replace_if(v.begin(), v.end(), MyReplace(), 10);
	for_each(v.begin(), v.end(), MyPrint());

}
int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//常用算术生成算法
//算术生成算法属于小型算法，使用时包含的头文件为#include<numeric>
//accumulate--计算容器元素累计总和
//fill--向容器中添加元素
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i + 100);
	}

	int num = accumulate(v.begin(), v.end(), 0);
	cout << "容器中元素的总和为：" << num << endl;
}
void test02()
{
	vector<int>v1;
	v1.resize(15);
	fill(v1.begin(), v1.end(), 10);
	for_each(v1.begin(), v1.end(), MyPrint());

}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}
#elif 1
//常用集合算法
//求两个容器的交集--set_intersection
//求两个容器的并集--set_union
//求两个容器的差集--set_difference

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vterget;
	vterget.resize(min(v1.size(), v2.size()));

	vector<int>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vterget.begin());
	for_each(vterget.begin(), it, MyPrint());
	cout << endl;
}

void test02()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vterget;
	vterget.resize(v1.size()+v2.size());
	vector<int>::iterator it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vterget.begin());
	for_each(vterget.begin(), it, MyPrint());
	cout << endl;

}

void test03()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int>vterget;
	vterget.resize(max(v1.size(), v2.size()));
	vector<int>::iterator it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vterget.begin());
	for_each(vterget.begin(), it, MyPrint());
	cout << endl;
}

int main()
{
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}

#endif
