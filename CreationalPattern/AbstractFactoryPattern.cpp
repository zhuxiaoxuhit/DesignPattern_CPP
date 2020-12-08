#include <iostream>

struct Cola{
	virtual void drink() = 0;
};

struct Burger{
	virtual void eat() = 0;
};

struct ColaKFC : public Cola{
	virtual void drink() override {std::cout << "Drink KFC Cola" << std::endl;}
};

struct BurgerKFC : public Burger{
	virtual void eat() override {std::cout << "Eat KFC Burger" << std::endl;}
};

struct ColaMD : public Cola{
	virtual void drink() override {std::cout << "Drink MD Cola" << std::endl;}
};

struct BurgerMD : public Burger{
	virtual void eat() override {std::cout << "Eat MD Burger" << std::endl;}
};

struct Factory{
	virtual Cola* createCola() = 0;
	virtual Burger* createBurger() = 0;
};

struct FactoryKFC : public Factory{
	virtual Cola* createCola() {return new ColaKFC();}
	virtual Burger* createBurger() {return new BurgerKFC();}
};

struct FactoryMD : public Factory{
	virtual Cola* createCola() {return new ColaMD();}
	virtual Burger* createBurger() {return new BurgerMD();}
};

int main(){
	FactoryKFC FK;
	FactoryMD FM;
	Cola* CK = FK.createCola();
	Burger* BK = FK.createBurger();
	Cola* CM = FM.createCola();
	Burger* BM = FM.createBurger();
	CK->drink();
	BK->eat();
	CM->drink();
	BM->eat();
	delete CK,BK,CM,BM;
	return 0;
}

