#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
using namespace std;
#include<iostream>
#include<fstream>


#if 0

//多态
//多态分为两类
//静态多态：函数重载和运算符重载属于静态多态，复用函数名
//动态多态：派生类和虚函数实现运行时多态

/*静态多态和动态多态的区别：
静态多态的函数地址早绑定-编译阶段确定函数地址
动态多态的函数地址晚绑定-运行阶段确定函数地址
*/

class Animal
{
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat:public Animal
{
public:
	void speak()
	{
		cout << "小猫在喵喵叫" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "狗子在汪汪叫" << endl;
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
//多态案例--计算器类
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

//纯虚函数和抽象类
class Base
{
	/*纯虚函数
	类中只要有一个纯虚函数就称为抽象类
	抽象类无法实例化对象
	子类必须重写父类中的虚函数，否则也属于抽象类*/
public:
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func()
	{
		cout << "国服马超参上！" << endl;
	}
};

void test()
{
	Base* base = NULL;
	//base = new Base;//错误，抽象类无法实例化对象
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
//多态案例二-制作饮品
class AbstractDrinking
{
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//规定流程
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
		cout << "煮一杯天山雪莲水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	virtual void PourInCup()
	{
		cout << "将咖啡倒入杯中" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入牛奶" << endl;
	}
};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "煮一杯82年的农夫山泉" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	virtual void PourInCup()
	{
		cout << "将茶水倒入杯中" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入凤爪" << endl;
	}
};

//业务函数
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
//虚析构和纯虚析构
class Animal
{
public:
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}
	virtual void Speak() = 0;

	//析构函数加上virtual关键字，变成虚析构函数
	/*virtual ~Animal()
	{
		cout << "Animal虚析构函数的调用！" << endl;
	}*/

	virtual ~Animal() = 0;

};

Animal::~Animal()
{
	cout << "Animal纯虚析构函数调用" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用！" << endl;
		m_Name = new string(name);
	}

	virtual void Speak()
	{
		cout << *m_Name << "小猫在说话！" << endl;
	}

	~Cat()
	{
		cout << "Cat析构函数调用" << endl;
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
		cout << "Base构造函数的调用" << endl;
	}
	virtual ~Base()
	{
		cout << "Base析构函数的调用" << endl;
	}

	virtual void speak() = 0;
};


class Son :public Base
{
public:
	void speak()
	{
		cout << "Son的speak函数调用" << endl;
	}

	Son()
	{
		cout << "son的构造函数调用" << endl;
	}
	~Son()
	{
		cout << "son的析构函数调用" << endl;
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
//写文件步骤如下
/*
* 1.包含头文件 fstream
* 2.创建流对象 
* 3.打开文件
* 4.写数据
* 5.关闭文件
*/

void test()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "姓名：西凉锦马超" << endl;
	ofs << "战绩：0/20/0" << endl;
	ofs.close();
}

#endif
