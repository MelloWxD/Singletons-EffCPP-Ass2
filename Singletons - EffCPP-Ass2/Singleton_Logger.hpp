#pragma once
#include"Singleton.hpp"

/// <summary>
/// A smarter approach to utilizing singletons quickly with templates abstracting the singleton implementation further away
/// Thanks to Mark Featherstone
/// </summary>
class TLogger : public TSingleton<TLogger>
{
public:
	/// <summary>
	/// Run all neccessary code before being used, this is done because the default constructor is hidden from us
	/// </summary>
	void init()
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
	TLogger() = default;
	~TLogger() = default;
private:
	std::vector<std::string> m_vLogOut;
	int logcnt = -1;
};

	
	


