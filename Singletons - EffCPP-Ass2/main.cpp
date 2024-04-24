#include<iostream>
#include"Singleton.hpp"
#include"Example1.hpp"













int main()
{
	std::cout << "Joe mama smelly\n";

	

	Logger::Get().init();
	Logger::Get().printLn("Fatty fatty boom boom");










	return 0;
}




