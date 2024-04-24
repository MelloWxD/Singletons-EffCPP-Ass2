
#pragma once
#include<vector>
#include<iostream>

/// <summary>
/// A typical Logger class that has no fancy design patterns.
/// We can still achieve the global usage by clever parsing of an instance around the codebase
/// However this may be more confusing than the other approaches
/// </summary>
class Logger
{
public:
	/// <summary>
	/// Run all neccessary code before being used, this is done because the default constructor is hidden from us
	/// </summary>
	Logger()
	{
		m_vLogOut.resize(0);
	}	
	~Logger()
	{
		m_vLogOut.resize(0);
	}
	/// <summary>
	/// Log a string
	/// </summary>
	/// <param name="log">string to be logged</param>
	void LogLn(std::string log)
	{
		m_vLogOut.push_back(log);
		++logcnt;
		std::cout << m_vLogOut[logcnt] << std::endl;

	}
	/// <summary>
	/// Prints all the log strings that have been handled by the function throughout runtime. 
	/// </summary>
	void printLog()
	{
		for (auto s : m_vLogOut)
		{
			std::cout << s << std::endl;	// Use cout for this to avoid clogging the vector
		}

	}
private:
	std::vector<std::string> m_vLogOut;
	int logcnt = -1;
};