#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

#if 0
//���������
//1.�Ӻ����������
class Person
{
public:
	Person()
	{
		m_A = 0;
		m_B = 0;
	}

	Person(int ma, int mb) :m_A(ma), m_B(mb)
	{

	}

	//��Ա����ʵ��+�����������
	//Person operator+(const Person& p)
	//{
	//	Person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}
public:
	int m_A;
	int m_B;
};

//ȫ�ֺ���ʵ��+�����������
Person operator+(const Person& p1, const Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//��������� ���Է�����������
Person operator+(const Person& p, int val)
{
	Person temp;
	temp.m_A = p.m_A + val;
	temp.m_B = p.m_B + val;
	return temp;
}
//��������������к�������
ostream& operator<<(ostream& out, Person& p)
{
	out << "p.mA = " << p.m_A << "p.mB = " << p.m_B;
	return out;
}

void test()
{
	Person p1(10, 20);
	Person p2(20, 30);
	Person p3 = p1 + p2;
	Person p4 = p1 + 10;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	cout << p4 << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}


#elif 0
//�������������
class MyInteger
{
	friend ostream& operator<<(ostream& out, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}

	//���ں���ʵ��ǰ��++���������
	MyInteger& operator++()
	{
		this->m_Num++;
		return *this;
	}

	//���ں���ʵ�ֺ���++���������
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		this->m_Num++;
		return temp;
	}

private:
	int m_Num;
};

//ȫ�ֺ���ʵ��<<�������������
ostream& operator<<(ostream& out, MyInteger myint)
{
	out << myint.m_Num;
	return out;
}

void test()
{
	MyInteger a;
	cout << a << endl;
	cout << ++a << endl;
	cout << a++ << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}


#elif 0
//��ֵ���������
class Person
{
public:
	Person()
	{
		m_age = NULL;
		m_height = 0;
		cout << "Person����ͨ������������" << endl;
	}

	Person(int age, int height)
	{
		cout << "Person���вι��캯������" << endl;
		m_age = new int(age);
		m_height = height;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}

	//���ظ�ֵ�����
	Person& operator=(Person& p)
	{
		if (this->m_age != NULL)
		{
			delete this->m_age;
			this->m_age = NULL;
		}
		//�������ṩ�ĸ�ֵ�������ǳ����
		this->m_age = new int(*p.m_age);
		this->m_height = p.m_height;
		return *this;

	}
private:
	int* m_age;
	int m_height;
};

void test()
{
	Person p(10, 180);
	Person a = p;
}

int main()
{
	system("pause");
	return 0;
}


#elif 0
//��ϵ���������
class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	bool operator==(Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

public:
	string m_Name;
	int m_Age;
};

void test()
{
	Person a("�����", 18);
	Person b("��˽�", 18);
	if (a == b)
	{
		cout << "a��b���" << endl;
	}
	else
	{
		cout << "a��b�����" << endl;
	}

	if (a != b)
	{
		cout << "a��b�����" << endl;
	}
	else
	{
		cout << "a��b���" << endl;
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 0
//�����������������
class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};

void test01()
{
	MyPrint myFunc;
	myFunc("hello world");
}

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	MyAdd add;
	int ret = add(10, 20);
	cout << "ret = " << ret << endl;

	//�����������
	cout << "ret = " << MyAdd()(10, 20) << endl;
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

#elif 0
class Base
{
public:
	Base()
	{
		cout << "Base���캯��" << endl;
	}
	~Base()
	{
		cout << "Base��������" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son���캯��" << endl;
	}
	~Son()
	{
		cout << "Son��������" << endl;
	}
};

void test()
{
	Son s;
}

int main()
{
	test();
	system("pause");
	return 0;
}


#elif 0
//�̳�ͬ����Ա����ʽ
class Base
{
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base-fun()����" << endl;
	}

	void func(int a)
	{
		cout << "Base-fun(int a)����" << endl;
	}

public:
	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	//�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
	//�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������

	void func()
	{
		cout << "Son-func()����" << endl;
	}
public:
	int m_A;
};


void test()
{
	Son s;
	cout << "Son�µ�m_A = " << s.m_A << endl;
	cout << "Base�µ�m_A = " << s.Base::m_A << endl;
	s.func();
	s.Base::func();
	s.Base::func(10);
}

int main()
{
	test();
	system("pause");
	return 0;
}
#elif 0
//��̳��﷨
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
public:
	int m_A;
};

class Son :public Base1, public Base2
{
public:
	Son()
	{
		Base1::m_A = 200;
		m_C = 300;
		m_D = 400;
	}
public:
	int m_C;
	int m_D;
};

#elif 1
//����������μ̳�����
class Animal
{

public:
	int m_Age;
};

class Sheep:virtual public Animal {};
class Tuo:virtual public Animal {};
class SheepTuo: public Sheep,public Tuo{};

void test()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}

#endif