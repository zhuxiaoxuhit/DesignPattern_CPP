#include <iostream>

class Singleton{
	public:
		static Singleton& getInstance();
	private:
		Singleton() = default;
};

Singleton& Singleton::getInstance(){
	static Singleton instance;
	return instance;
}


int main(){
	Singleton instance = Singleton::getInstance();
}





