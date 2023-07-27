#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

#if 0

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m;//默认构造
	m.insert(pair<int, int>(1, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 50));
	m.insert(pair<int, int>(4, 40));

	printMap(m);
	
	//拷贝构造
	map<int, int>m2(m);
	printMap(m2);

	//赋值操作
	map<int, int>m3;
	m3 = m;
	printMap(m3);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//map大小和交换--统计map容器大小以及交换map容器

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty())
	{
		cout << "map容器m为空！" << endl;
	}
	else
		cout << "map容器m不为空，大小为：" << m.size() << endl;

}

//交换
void test02()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));

	cout << "交换前：" << endl;
	printMap(m1);
	printMap(m2);

	cout << "交换后：" << endl;
	m1.swap(m2);
	printMap(m1);
	printMap(m2);

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}


#elif 0
//map插入和删除--对map容器进行插入数据和删除数据
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	//插入
	map<int, int>m;
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m.insert(make_pair(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式
	m[4] = 40;

	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(30);//这种删除方式是对key值进行索引
	printMap(m);

	//清空
	m.clear();
	printMap(m);

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//map查找和统计--对map容器进行查找数据以及统计数据
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	//查找
	map<int, int>::iterator it = m1.find(3);
	if (it != m1.end())
	{
		cout << "找到key值为3的元素：" << it->second << endl;
	}
	else
	{
		cout << "该值不存在" << endl;
	}

	//统计
	int num = m1.count(3);
	cout << "num = " << num << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//map容器排序
//map容器默认排序规则为按照key值进行从小到大排序，掌握如何改变排序规则
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};

void printMap2(map<int, int, MyCompare>& M)
{
	for (map<int, int, MyCompare>::iterator it = M.begin(); it != M.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}



void test01()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(3, 10));
	m1.insert(pair<int, int>(2, 10));
	m1.insert(pair<int, int>(4, 10));

	printMap(m1);

	map<int, int, MyCompare>m2;
	m2.insert(pair<int, int>(5, 20));
	m2.insert(pair<int, int>(1, 10));
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(3, 70));
	m2.insert(pair<int, int>(2, 30));
	printMap2(m2);

}

int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string name;
	int salary;
};

void CreateWorker(vector<Worker>& v)
{
	string name = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.name = "员工";
		worker.name += name[i];
		worker.salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}


void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int bianhao = rand() % 3;
		m.insert(pair<int, Worker>(bianhao, *it));
	}
}

void showWorkerGroup(multimap<int, Worker>& m)
{

	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int num = m.count(CEHUA);
	for (int i = 0; i < num; i++, pos++)
	{
		if (pos != m.end())
		{
			cout << " 姓名：" << pos->second.name << " 工资" << pos->second.salary << endl;
		}
	}

	cout << "--------------------------------" << endl;

	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	num = m.count(MEISHU);
	for (int i = 0; i < num; i++, pos++)
	{
		if (pos != m.end())
		{
			cout << " 姓名：" << pos->second.name << " 工资" << pos->second.salary << endl;
		}
	}

	cout << "--------------------------------" << endl;

	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	num = m.count(YANFA);
	for (int i = 0; i < num; i++, pos++)
	{
		if (pos != m.end())
		{
			cout << " 姓名：" << pos->second.name << " 工资" << pos->second.salary << endl;
		}
	}
}


int main()
{
	//1.创建员工
	vector<Worker>vWorker;
	CreateWorker(vWorker);

	/*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "姓名：" << it->name << " 工资：" << it->salary << endl;
	}*/

	//员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

	//员工信息打印
	showWorkerGroup(mWorker);

	system("pause");
	return 0;
}


#elif 0
/*
函数对象：
重载函数调用操作符的类，其对象称为函数对象
函数对象使用重载的()时，行为类似函数调用，也叫仿函数

特点：
函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
函数对象超出普通函数的概念，函数对象可以有自己的状态
函数对象可以作为参数传递
*/

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test01()
{
	MyAdd add;
	cout << add(10, 10) << endl;
}

//函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->num = 0;
	}
public:
	void operator()(string x)
	{
		cout << x << endl;
		this->num++;
	}

	int num;//内部自己的状态
};
void test02()
{
	MyPrint print;
	print("hello");
	cout << "调用的次数：" << print.num << endl;
}

//函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}

void test03()
{
	MyPrint myprint;
	doPrint(myprint, "hello");
}

#elif 0

/*
返回bool类型的仿函数称为谓词
如果operator（）接受一个参数，那么叫做一元谓词
如果operator（）接受两个参数，那么叫做二元谓词
*/
struct GreaterFive
{
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
	if (it != v.end())
	{
		cout << *it << endl;
	}

}

int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0
//二元谓词
class MyCompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

#elif 1
//内建函数对象
/*
* plus<T>//加法仿函数
* minus<T>--减法仿函数
* multiplies--乘法仿函数
* divides--除法仿函数
* modulus--取模仿函数
* negate--取反仿函数
* 除了取反仿函数是一元运算，其他都是二元运算
*/

void test01()
{
	negate<int>n;
	cout << n(50) << endl;

	plus<int>p;
	cout << p(50, 30) << endl;

	minus<int>m;
	cout << m(6, 2) << endl;

	multiplies<int>mul;
	cout << mul(2, 3) << endl;


}

void test02()
{
	vector<int>v;
	v.push_back(18);
	v.push_back(29);
	v.push_back(10);
	v.push_back(83);
	v.push_back(1);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test02();
	system("pause");
	return 0;
}

#endif