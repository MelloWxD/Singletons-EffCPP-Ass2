#include"Singleton.hpp"
#include<iostream>
#include<string>
#include<vector>



/// <summary>
///  Logger Class.
/// This is a singleton class used for logging outputs from anywhere in the codebase
/// </summary>
class Logger
{
public:
	
	/// <summary>
	/// Get the instance of the Logger object.
	/// </summary>
	/// <returns>Logger instance</returns>
	static Logger& Get() 
	{
		static Logger instance;
		return instance;
	}
		
	/// <summary>
	/// Run all neccessary code before being used, this is done because the default constructor is hidden from us
	/// </summary>
	void init() 
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


class TLogger : public Singleton<TLogger>
{

public:
	/// <summary>
	/// Run all neccessary code before being used, this is done because the default constructor is hidden from us
	/// </summary>
	void init()
	{
		m_vLogOut.resize(0);
	}

	void printLn(std::string log)
	{
		m_vLogOut.push_back(log);
		++logcnt;
		std::cout << m_vLogOut[logcnt] << std::endl;

	}
	TLogger() = default;
	~TLogger() = default;
	std::vector<std::string> m_vLogOut;
	int logcnt = -1;





};

	
	


