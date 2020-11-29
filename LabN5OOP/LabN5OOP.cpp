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
	delete p1;
	delete p2;
	//3
	cout << "Проверка на принадлежность некоторому классу:\n";
	return 0;
}