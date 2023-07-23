#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<vector>



#if 0
//容器算法迭代器初始


void MyPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator vBegin = v.begin();
	vector<int>::iterator vEnd = v.end();

	//第一种遍历方式
	while (vBegin != vEnd)
	{
		cout << *vBegin;
		vBegin++;
	}
	cout << endl;

	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}
	cout << endl;

	//第三种遍历方式
	//使用STL提供遍历算法 头文件algorithm
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0
//vector容器嵌套容器
void test01()
{
	vector<vector<int>>v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
		v3.push_back(i + 2);
		v4.push_back(i + 3);
		v5.push_back(i + 4);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit<<" ";
		}
		cout << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0

//string概念
//string的几种构造方法
void test01()
{
	string s1;//创建空字符串，调用无参构造函数
	cout << "str1=" << s1 << endl;

	const char* str = "hello world";
	string s2(str);
	cout << "str2=" << s2 << endl;

	//使用一个string对象初始化另一个string对象
	string s3(s2);
	cout << "str3=" << s3 << endl;

	//使用n个字符c初始化
	string s4(5, 'a');
	cout << "str4=" << s4 << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//给string字符串进行赋值
void test01()
{
	string str1;
	str1 = "wdnmd";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2<< endl;

	string str3;
	str3 = 'c';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("qunimade");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("helloworld", 3);
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str4);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(3, 'c');
	cout << "str7 = " << str7 << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}


#elif 0
//string 字符串拼接
void test01()
{
	string str1;
	str1 = "我是大帅比";
	cout << "str1=" << str1 << endl;

	str1 += " 才怪";
	cout << "str1=" << str1 << endl;

	str1 += 'a';
	cout << "str1=" << str1 << endl;

	string str;
	str = "haha";
	str1 += str;
	cout << "str1=" << str1 << endl;

	str1.append("骗你的");
	cout << "str1=" << str1 << endl;

	str1.append("cccc", 2);
	cout << "str1=" << str1 << endl;
	
	str1.append(str);
	cout << "str1=" << str1 << endl;

	str1.append(str, 2, 2);
	cout << "str1=" << str1 << endl;


}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0

//查找和替换
void test01()
{
	//查找
	string str1 = "abcdefghijkl";
	string str2 = "de";
	int pos = str1.find(str2);
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str2第一次出现的位置为 " << pos << endl;


	//替换
	str1.replace(2, 3, str2);
	cout << "替换后的str1为 " << str1 << endl;

	str1.replace(2, 1, "haha");
	cout << "替换后的str1为 " << str1 << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//string字符串的比较
//字符串的比较是安装ASCII码进行比较

void test01()
{
	string str1 = "hello";
	string str2 = "ehello";

	if (str1.compare(str2) == 0)
	{
		cout << "str1与str2相等" << endl;
	}
	else if(str1.compare(str2) > 0)
	{
		cout << "str1>str2" << endl;
	}
	else
	{
		cout << "str1<str2" << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0

//字符串插入和删除
void test01()
{
	string str = "hello";
	str.insert(1, "111");
	cout << "str = " << str << endl;

	string str1 = "nmd";
	str.insert(2, str1);
	cout << "str = " << str << endl;

	str.erase(3, 2);
	cout << "str = " << str << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 1
//string子串

void test01()
{
	string str = "abcdefgh";
	string str1 = str.substr(0,3);
	cout << "str1 = " << str1 << endl;

	string email = "1412369354@qq.com";
	int pos = email.find('@');
	string qq = email.substr(0, pos);
	cout << "qq=" << qq << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#endif
