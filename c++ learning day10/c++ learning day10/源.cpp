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
�߼��º���--ʵ���߼�����
bool logical_and �߼���
bool logical_or �߼���
bool logical_not �߼���
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
//�����㷨
//���ñ����㷨

//��ͨ����
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
//transform--������������һ��������
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
		string s2 = "����";
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
//���ò����㷨--���ճ��õĲ����㷨
//find--����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()

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
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�:" << *it << endl;
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
		cout << "�ҵ��ˣ�" << " ������" << it->age << " ��ߣ�" << it->high << endl;
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
//��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//beg��ʼ������
//end����������
//_Pred��������ν�ʣ�����bool���͵ķº�����


//������������
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
		cout << "û�ҵ���" << endl;
	}
	else
	{
		cout << "�ҵ�����5�����֣�" << *it << endl;
	}
}

//�Զ�����������
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
		cout << "�ҵ��ˣ�����Ϊ��" << it->m_age << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
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
//adjacent_find--���������ظ�Ԫ��
//���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
//beg��ʼ������
//end����������

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
		cout << "���ڵ��ظ�Ԫ��Ϊ��" << *it << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//bool binary_search--����ָ����Ԫ�أ��鵽����true����false
//���ֲ��ҷ�--ֻ�������������вſ���ʹ��
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	bool ret = binary_search(v.begin(), v.end(), 3);
	if (ret)
		cout << "�ҵ���" << endl;
	else
		cout << "δ�ҵ�" << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//count--ͳ��Ԫ�س��ִ���

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
	cout << "Ԫ�س��ֵĴ���Ϊ��" << num << endl;
}

void test02()
{
	vector<Person>v;
	Person p1("����", 13);
	Person p2("����", 12);
	Person p3("�����", 14);
	Person p4("ͳ��", 13);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("����", 13);

	int num = count(v.begin(), v.end(), pp);
	cout << "Ԫ�س��ֵĴ���Ϊ��" << num << endl;
}


int main()
{
	test02();
	system("pause");
	return 0;
}

#elif 0
//count_if������ͳ��Ԫ�ظ���
//count_if������ͳ��Ԫ�س��ִ���

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
	Person p1("����", 13);
	Person p2("����", 23);
	Person p3("�����", 14);
	Person p4("ͳ��", 13);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	for_each(v.begin(), v.end(), MyPrint);

	int num = count_if(v.begin(), v.end(), Greatershi());
	cout << "����20�ĸ���Ϊ��" << num << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

#elif 0
//���������㷨--sort

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

	//sortĬ�ϴ�С��������
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
//random_shuffle--ϴ�� ָ����Χ�ڵ�Ԫ�������������
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
//merge--��������Ԫ�غϲ������洢����һ������
//�������������������

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
	//Ŀ������ǰ���ٿռ�
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
//reverse--��������Ԫ�ؽ��з�ת
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
//���ÿ������滻�㷨
//copy--��������
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
//replace--��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
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
//replace_if--������������������Ԫ�أ��滻��ָ��Ԫ��
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
//�������������㷨
//���������㷨����С���㷨��ʹ��ʱ������ͷ�ļ�Ϊ#include<numeric>
//accumulate--��������Ԫ���ۼ��ܺ�
//fill--�����������Ԫ��
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
	cout << "������Ԫ�ص��ܺ�Ϊ��" << num << endl;
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
//���ü����㷨
//�����������Ľ���--set_intersection
//�����������Ĳ���--set_union
//�����������Ĳ--set_difference

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
