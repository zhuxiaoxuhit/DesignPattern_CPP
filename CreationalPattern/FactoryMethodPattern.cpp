#include <iostream>

struct Product{
	virtual void use() = 0;
};

struct ProductA : public Product{
	virtual void use() override {std::cout << "Product A" << std::endl;}
};

struct ProductB : public Product{
	virtual void use() override {std::cout << "Product B" << std::endl;}
};

struct Factory{
	virtual Product* createProduct() = 0;
};

struct FactoryA : public Factory{
	virtual Product* createProduct() override {return new ProductA();}
};

struct FactoryB : public Factory{
	virtual Product* createProduct() override {return new ProductB();}
};

int main(){
	FactoryA FA;
	FactoryB FB;
	Product* PA = FA.createProduct();
	Product* PB = FB.createProduct();
	PA->use();
	PB->use();
	delete PA,PB;
	return 0;
}


