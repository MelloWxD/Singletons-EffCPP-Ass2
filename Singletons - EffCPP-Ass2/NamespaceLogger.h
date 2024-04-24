#pragma once
#include<string>
#include<vector>
#include<iostream>

namespace NSLogger
{
	// Define static variables
	static std::vector<std::string> s_vLogOut;
	static int s_iLogcnt;

	void NSLogInit()
	{
		s_vLogOut.resize(0); // initialize static variables with safe defaults
		s_iLogcnt = -1;
	}
	/// <summary>
	/// Log a string
	/// </summary>
	/// <param name="log">string to be logged</param>
	void NSLogLn(std::string log)
	{
		s_vLogOut.push_back(log);
		++s_iLogcnt;
		std::cout << s_vLogOut[s_iLogcnt] << std::endl;

	}

	/// <summary>
	/// Prints all the log strings that have been handled by the function throughout runtime. 
	/// </summary>
	void NSprintLog()
	{
		for (auto s : s_vLogOut)
		{
			std::cout << s << std::endl;	// Use cout for this to avoid clogging the vector
		}
		std::cout << "\n\n\n\n"; // clear space
	}




}