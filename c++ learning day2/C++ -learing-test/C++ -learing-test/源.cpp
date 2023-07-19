#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
using namespace std;
#include<iostream>
#include<fstream>


#if 0

//��̬
//��̬��Ϊ����
//��̬��̬���������غ�������������ھ�̬��̬�����ú�����
//��̬��̬����������麯��ʵ������ʱ��̬

/*��̬��̬�Ͷ�̬��̬������
��̬��̬�ĺ�����ַ���-����׶�ȷ��������ַ
��̬��̬�ĺ�����ַ���-���н׶�ȷ��������ַ
*/

class Animal
{
public:
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat:public Animal
{
public:
	void speak()
	{
		cout << "Сè��������" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "������������" << endl;
	}
};

void animaltalk(Animal& animal)
{
	animal.speak();
}

void test()
{
	Cat a;
	animaltalk(a);
	Dog b;
	animaltalk(b);
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 0
//��̬����--��������
class AbstractCalculator
{
public:
	virtual int getResult(int a,int b) = 0;


};

class AddCalculator:public AbstractCalculator
{
public:
	int getResult(int a,int b)
	{
		return a + b;
	}
};

void test()
{
	AbstractCalculator* abc = new AddCalculator;
	cout << abc->getResult(10, 10) << endl;
	delete abc;
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 0

//���麯���ͳ�����
class Base
{
	/*���麯��
	����ֻҪ��һ�����麯���ͳ�Ϊ������
	�������޷�ʵ��������
	���������д�����е��麯��������Ҳ���ڳ�����*/
public:
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func()
	{
		cout << "���������ϣ�" << endl;
	}
};

void test()
{
	Base* base = NULL;
	//base = new Base;//���󣬳������޷�ʵ��������
	base = new Son;
	base->func();
	delete base;
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 0
//��̬������-������Ʒ
class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//�涨����
	void MakeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "��һ����ɽѩ��ˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	virtual void PourInCup()
	{
		cout << "�����ȵ��뱭��" << endl;
	}
	virtual void PutSomething()
	{
		cout << "����ţ��" << endl;
	}
};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "��һ��82���ũ��ɽȪ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	virtual void PourInCup()
	{
		cout << "����ˮ���뱭��" << endl;
	}
	virtual void PutSomething()
	{
		cout << "�����צ" << endl;
	}
};

//ҵ����
void doWork(AbstractDrinking* abc)
{
	abc->MakeDrink();
	delete abc;
}

void test()
{
	doWork(new Coffee);
	cout << "-------------" << endl;
	doWork(new Tea);
}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 0
//�������ʹ�������
class Animal
{
public:
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}
	virtual void Speak() = 0;

	//������������virtual�ؼ��֣��������������
	/*virtual ~Animal()
	{
		cout << "Animal�����������ĵ��ã�" << endl;
	}*/

	virtual ~Animal() = 0;

};

Animal::~Animal()
{
	cout << "Animal����������������" << endl;
}

//�Ͱ�����ͨ���麯������һ���������˴���������������Ҳ��һ�������ࡣ���ܹ���ʵ����

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat���캯�����ã�" << endl;
		m_Name = new string(name);
	}

	virtual void Speak()
	{
		cout << *m_Name << "Сè��˵����" << endl;
	}

	~Cat()
	{
		cout << "Cat������������" << endl;
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}

public:
	string* m_Name;
};

void test()
{
	Animal* abc = new Cat("mimi");
	abc->Speak();
	delete abc;

}

int main()
{
	test();
	system("pause");
	return 0;
}

#elif 0
class Base
{
public:
	Base()
	{
		cout << "Base���캯���ĵ���" << endl;
	}
	virtual ~Base()
	{
		cout << "Base���������ĵ���" << endl;
	}

	virtual void speak() = 0;
};


class Son :public Base
{
public:
	void speak()
	{
		cout << "Son��speak��������" << endl;
	}

	Son()
	{
		cout << "son�Ĺ��캯������" << endl;
	}
	~Son()
	{
		cout << "son��������������" << endl;
	}
};


void test()
{
	Base* abc = new Son;
	abc->speak();
	delete abc;
}
int main()
{
	test();
	system("pause");
	return 0;
}

#elif 1
//д�ļ���������
/*
* 1.����ͷ�ļ� fstream
* 2.���������� 
* 3.���ļ�
* 4.д����
* 5.�ر��ļ�
*/

void test()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "��������������" << endl;
	ofs << "ս����0/20/0" << endl;
	ofs.close();
}

#endif
