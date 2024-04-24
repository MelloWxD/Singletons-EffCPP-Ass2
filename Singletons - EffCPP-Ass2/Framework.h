#pragma once
#include<iostream>
#include<iostream>
#include<string>
#include<vector>
#include"Singleton_Logger.hpp"
#include"NamespaceLogger.h"
#include"Logger.h"
/// <summary>
/// Framework class for demonstrating Out of scope access
/// to functions discussed in report and updating the interface.
/// </summary>
class Framework
{
public:
	Framework()
	{
		NSLogger::NSLogInit(); // call the init for the namespace demonstration
	}
	~Framework()
	{
	}

	/// <summary>
	/// updates the program logic for the singleton Approach example.
	/// </summary>
	void updateSingletonsLoop()
	{
		if (!m_bExit)
		{
			// Multiple uses of TLogger class being used outside of its defined scope due to 
			//	the singleton design approach used.
			std::cout << ("Please press a key\n1. Log a string\n2. Output debug Log\n3.Exit\n");
			int Iinput = 0;
			std::string Sinput;
			std::cin >> Iinput;

			switch (Iinput)
			{
			case 1:
				system("cls");
				std::cout << ("Please enter the Log:\t");
				std::cin >> Sinput;
				TLogger::Get().LogLn(Sinput);

				std::cout << ("Log entered thank you.\n");
				break;
			case 2:
				system("cls");
				TLogger::Get().printLog();
				break;
			case 3:
				m_bExit = true;
				break;
			default:
				system("cls");
				break;
			}
		}

	}

	/// <summary>
	/// updates the program logic for the Passing Approach example.
	/// </summary>
	/// <param name="pLogger">pointer to Logger Instance</param>
	void updateParsedLoop(Logger* pLogger)
	{
		if (!m_bExit)
		{
			// Multiple uses of TLogger class being used outside of its defined scope due to 
			//	the singleton design approach used.
			std::cout << ("Please press a key\n1. Log a string\n2. Output debug Log\n3.Exit\n");
			int Iinput = 0;
			std::string Sinput;
			std::cin >> Iinput;

			switch (Iinput)
			{
			case 1:
				system("cls");
				std::cout << ("Please enter the Log:\t");
				std::cin >> Sinput;
				pLogger->LogLn(Sinput);
				
				std::cout << ("Log entered thank you.\n");
				break;
			case 2:
				system("cls");
				pLogger->printLog();
				break;
			case 3:
				m_bExit = true;
				break;
			default:
				system("cls");
				break;
			}
		}

	}

	/// <summary>
	/// updates the program logic for the Namepsace Approach example.
	/// </summary>
	void updateNamspaceLoop()
	{
		using namespace NSLogger; // use the namspace to avoid long strings i.e. NSLogger::NSLogprintLn("blahblahblah");
		if (!m_bExit)
		{
			// Multiple uses of NSLogger class being used outside of its defined scope due to 
			//	the singleton design approach used.
			std::cout << "Please press a key\n1. Log a string\n2. Output debug Log\n3.Exit\n";
			int Iinput = 0;
			std::string Sinput;
			std::cin >> Iinput;
			
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
				Iinput = 0;
			}
			switch (Iinput)
			{
				
			case 1:
				system("cls");
				std::cout << ("Please enter the Log:\t");
				std::cin >> Sinput;
				NSLogLn(Sinput);

				std::cout << ("Log entered thank you.\n");
				break;
			case 2:
				system("cls");
				NSprintLog();
				break;


			case 3:
				m_bExit = true;
				break;

			default:
				system("cls");
				break;

			}
		}

	}

	bool getExitStatus()
	{
		return m_bExit;
	}	
	bool setExitStatus(bool b)
	{
		m_bExit = b;
	}
private:
	int Iinput = 0;				// Selection screen choice
	std::string Sinput = "";	// String typing because we care about displaying the results in a readable format
	bool m_bExit = false;		// Exit status
};


