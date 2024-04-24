#include<iostream>
#include"Singleton.hpp"
#include"Example1.hpp"













int main()
{
	std::cout << "Program Entry Point\n";

	


	Logger::Get().printLn("Logger test output"); 

	new TLogger;

	TLogger::Get().printLn("TLogger test output");


	bool exit = false;
	while (!exit)
	{
		std::cout << "Please press a key\n1. Log a string\n2. Output debug Log\n3.Exit\n";

		int Iinput = 0;
		std::string Sinput;

		std::cin >> Iinput;
		switch (Iinput)
		{
		case 1:
			std::cout << "Please enter the Log:\t";
			std::cin >> Sinput;
			Logger::Get().printLn(Sinput);
			break;
		case 2:
			Logger::Get().printLog();
			break;
		case 3:
			exit = true;
			break;
		default:
			std::cout << "Please press a key\n1. Log a string\n2. Output debug Log\n3.Exit\n";
			std::cin.get() >> Iinput;
			break;
		}
	}






	
	return 0;
}




