#include <iostream>

class Target{
	public:
		virtual void operation1() = 0;
		virtual void operation2() = 0;
};

class Adaptee{
	public:
		virtual void specialOperation() {std::cout << "Special Operation" << std::endl;}
};

class Adapter : public Target{
	public:
		virtual void operation1() override {std::cout << "Operation1" << std::endl;}
		virtual void operation2() override {adaptee_.specialOperation();}
	private:
		Adaptee adaptee_;
};

int main(){
	Adapter a;
	a.operation1();
	a.operation2();
}


