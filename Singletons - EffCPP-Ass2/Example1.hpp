#include"Singleton.hpp"
#include<iostream>
#include<string>
#include<vector>

class Logger
{
public:
	static Logger& Get() {
		static Logger instance;
		return instance;
	}
		

	void init() // Initialize
	{
		m_vLogOut.resize(0);
		new Logger;
	}

	void printLn(std::string log)
	{
		m_vLogOut.push_back(log);
		++logcnt;
		std::cout << m_vLogOut[logcnt] << std::endl;

	}
private:
	Logger() = default;
	~Logger() = default;
	std::vector<std::string> m_vLogOut;
	int logcnt = -1;

};




	
	



	
private:

	//===============================================================================
	// Singleton Implementations (Banned functions to prevent a new instance)
	Logger() = default;										// Default Constructor private so can only be called from within
	//===============================================================================
};
