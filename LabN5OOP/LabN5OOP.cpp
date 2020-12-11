#include <iostream>

using namespace std;

class Parent {	// Класс-предок
public:
	Parent() {
		cout << "Parent()\n";
	}
	virtual	~Parent() {
		cout << "~Parent()\n";
	}
	void Print() {
		cout << "Parent\n";
	}
};

class Child1 : public Parent {	// Класс-наследник1
public:
	Child1() {
		cout << "Child1()\n";
	}
	virtual ~Child1() {
		cout << "~Child1()\n";
	}
};

class Child2 : public Parent {	//// Класс-наследник2
public:
	Child2() {
		cout << "Child2()\n";
	}
	virtual ~Child2() {
		cout << "~Child2()\n";
	}
	void Print() {
		cout << "Child2\n";
	}
};

class Point2D {	// Класс-предок
protected:
	int x, y;
public:
	Point2D() {
		x = y = 0;
		cout << "Point2D()\n";
	}
	virtual ~Point2D() {
		cout << "~Point2D()\n";
	}
	virtual void print1() {
		cout << x << ", " << y << endl;
	}
	void print2() {
		cout << "Point2D\n";
	}
	virtual string classname() {	// Метод получения имени класса
		return "Point2D";
	}
	virtual bool isA(string who) {	// Проверка принадлежности классу
		return (who == "Point2D");
	}
};

class Point3D : public Point2D {	// Класс-наследник
protected:
	int z;
public:
	Point3D() {
		z = 0;
		cout << "Point3D()\n";
	}
	virtual ~Point3D() {
		cout << "~Point3D()\n";
	}
	void print1() {
		cout << x << ", " << y << ", " << z << endl;
	}
	void print2() {
		cout << "Point3D\n";
	}
	string classname() {	// Метод получения имени класса
		return "Point3D";
	}
	bool isA(string who) {	// Проверка принадлежности классу
		return (who == "Point3D" || Point2D::isA(who));
	}
};

class Base {	// Класс-предок
public:
	Base() {
		cout << "Base()\n";
	}
	Base(Base* obj) {
		cout << "Base(Base* obj)\n";
	}
	Base(Base& obj) {
		cout << "Base(Base& obj)\n";
	}
	virtual	~Base() {
		cout << "~Base()\n";
	}
};

class Desc : public Base {	// Класс-наследник
public:
	Desc() {
		cout << "Desc()\n";
	}
	Desc(Desc* obj) {
		cout << "Desc(Desc* obj)\n";
	}
	Desc(Desc& obj) {
		cout << "Desc(Desc& obj)\n";
	}
	virtual	~Desc() {
		cout << "~Desc()\n";
	}
};

void func1(Base  obj) {

}
void func2(Base* obj) {

}
void func3(Base& obj) {

}


int main()
{
	setlocale(LC_ALL, "Russian");
	//1
	cout << "Перекрывание методов:\n";
	Child1 ch1;
	Child2 ch2;
	ch1.Print();	//Не перекрытй метод
	ch2.Print();	//Перекрытый метод
	//2
	cout << "Виртуальные методы:\n";
	Point2D* p1 = new Point2D;
	Point2D* p2 = new Point3D;
	p1->print1();	// Виртуальный метод
	p2->print1();
	p1->print2();	// Не виртуальный метод
	p2->print2();
	//3
	cout << "Проверка на принадлежность некоторому классу:\n";
	cout << "p1 это Point3D:" << p1->isA("Point3D") << endl;
	cout << "p2 это Point3D:" << p2->isA("Point3D") << endl;
	//4
	cout << "Безопасный метод приведения типов (dynamic_cast):\n";
	Point3D* p3 = new Point3D;
	Point2D* p4 = dynamic_cast<Point2D*>(p3);	// Приведение p3 к типу Point2D
	p4->print2();	//Вызываем виртуальный метод
	delete p3;
	//5
	cout << "Безопасный метод приведения типов (вручную)\n";
	p3 = new Point3D;
	if (p3->isA("Point2D")) {
		((Point2D*)p3)->print2();	//Приводим p3 к типу Point2D и вызываем виртуальный метод
	}
	//6
	cout << "Передача объектов как параметров в функции\n";
	cout << "f1\n";
	Base base1;
	func1(base1);	// Передача переменной
	cout << "f2\n";
	Base* base2 = new Base();
	func2(base2);	// Передача указателя
	cout << "f3\n";
	Base& base3 = *new Base();
	func3(base3);	// Передача ссылки
	cout << "f1\n";
	Desc desc1;
	func1(desc1);	// Передача переменной
	cout << "f2\n";
	Desc* desc2 = new Desc();
	func2(desc2);	// Передача указателя
	cout << "f3\n";
	Desc& desc3 = *new Desc();
	func3(desc3);	// Передача ссылки
	cout << "---\n";
	delete p1;
	delete p2;
	delete p3;
	delete base2;
	delete desc2;
	delete& base3;
	delete& desc3;
	return 0;
}