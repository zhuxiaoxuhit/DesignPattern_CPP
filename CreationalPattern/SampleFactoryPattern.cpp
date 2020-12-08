#include <iostream>
#include <string>

struct Product{
	virtual void use() = 0;
};

struct ProductA : public Product{
	virtual void use() override {std::cout << "Using Product A" << std::endl;}
};

struct ProductB : public Product{
	virtual void use() override {std::cout << "Using Product B" << std::endl;}
};

struct Factory{
	Product* createProduct(std::string str);
};

Product* Factory::createProduct(std::string str){
	if (str == "ProductA"){ return new ProductA();}
	else if (str == "ProductB") {return new ProductB();}
}

int main(){
	Factory F;
	Product* PA = F.createProduct("ProductA");
	Product* PB = F.createProduct("ProductB");
	PA->use();
	PB->use();
	delete PA,PB;
	
	return 0;
}

