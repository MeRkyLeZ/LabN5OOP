#include <iostream>

using namespace std;

class Parent {
public:
	Parent() {
		//cout << "Parent()\n";
	}
	virtual	~Parent() {
		//cout << "~Parent()\n";
	}
	void Print() {
		cout << "Parent\n";
	}
};

class Child1 : public Parent {
public:
	Child1() {
		//cout << "Child1()\n";
	}
	virtual ~Child1() {
		//cout << "~Child1()\n";
	}
};

class Child2 : public Parent {
public:
	Child2() {
		//cout << "Child2()\n";
	}
	virtual ~Child2() {
		//cout << "~Child2()\n";
	}
	void Print() {
		cout << "Child2\n";
	}
};

int main()
{
	Child1 ch1;
	Child2 ch2;
	ch1.Print();
	ch2.Print();
}