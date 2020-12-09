#include <iostream>

class Target{
	public:
		virtual void operation1() {std::cout << "Operation 1" << std::endl;}
		virtual void operation2() {std::cout << "Operation 2" << std::endl;}
};

class Adaptee{
	public:
		void specialoperation() {std::cout << "Special Operation" << std::endl;}
};

class Adapter : public Target{
	public:
		virtual void operation2() override {adaptee_.specialoperation();}
	private:
		Adaptee adaptee_;
};

int main(){
	Adapter adapter;
	adapter.operation1();
	adapter.operation2();
	return 0;
}

