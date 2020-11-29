#include <iostream>

using namespace std;

class Parent {
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

class Child1 : public Parent {
public:
	Child1() {
		cout << "Child1()\n";
	}
	virtual ~Child1() {
		cout << "~Child1()\n";
	}
};

class Child2 : public Parent {
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

class Point2D {
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
	virtual string classname() {
		return "Point2D";
	}
	virtual bool isA(string who) {
		return (who == classname());
	}
};

class Point3D : public Point2D {
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
	string classname() {
		return "Point3D";
	}
	bool isA(string who) {
		return (who == classname() || Point2D::isA(who));
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	//1
	cout << "Перекрывание методов:\n";
	Child1 ch1;
	Child2 ch2;
	ch1.Print();
	ch2.Print();
	//2
	cout << "Виртуальные методы:\n";
	Point2D* p1 = new Point2D;
	Point2D* p2 = new Point3D;
	p1->print1();
	p2->print1();
	p1->print2();
	p2->print2();
	//3
	cout << "Проверка на принадлежность некоторому классу:\n";
	cout << "p1 это Point3D:" << p1->isA("Point3D") << endl;
	cout << "p2 это Point3D:" << p2->isA("Point3D") << endl;
	//4
	cout << "Безопасный метод приведения типов (dynamic_cast):\n";
	Point3D *p3 = new Point3D;
	Point2D *p4 = dynamic_cast<Point2D*>(p3);
	p4->print2();
	//5
	cout << "Безопасный метод приведения типов (вручную)\n";

	delete p1;
	delete p2;
	delete p3;
	return 0;
}