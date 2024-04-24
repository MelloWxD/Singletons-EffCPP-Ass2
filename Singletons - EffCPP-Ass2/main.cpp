#include<iostream>
#include"Singleton.hpp"
#include"Example1.hpp"













int main()
{
	std::cout << "Program Entry Point\n";

	



	Logger::Get().printLn("Logger test output");

	new TLogger;

	TLogger::Get().printLn("TLogger test output");





	




	std::cin; // pause until keyboard input

	return 0;
}




