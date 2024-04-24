#include<assert.h>

// by Mark Featherstone(C) 2019 All Rights Reserved.
#ifndef SINGLETON_H
#define SINGLETON_H

/*
We often want only one instance of an object, especially if we are creating manager classes
to hold onto groups of objects and manage their lifetime. A singleton is a "design pattern"
designed to do just that - ensure there is only ever one instance of a specific class.

As we'll use it again and again, we don't want to repeat ourselves, this template and the
two macros help us write less code to get the job done.
Example - declaration
---------------------
	#include "Singleton.h"
	class ModeManager : public Singleton<ModeManager>
	{
	public:
		//add all your functions and data
	};

Example - in use
----------------
	new ModeManager;
	....
	ModeManager::Get()->DoStuff();
	....
	delete GetModeManager();

*/

// Written by Mark Featherstone
// Commented Explanation by Liam Hamit

template<class T> class Singleton // Templetized type allocation allowing for easy plug and play singleton instantiation of generic types/classes
{
public:
	Singleton()				// Abstracted Constructer using RAII
	{
		assert(spSingleton == nullptr);
		spSingleton = static_cast<T*>(this);
	}

	virtual ~Singleton()	// Abstracted Destructor using RAII
	{
		assert(spSingleton != nullptr);
		spSingleton = nullptr;
	}

	static T& Get()
	{	// Get function, used to return the instance of the singleton
		assert(spSingleton != nullptr);
		return *spSingleton;
	}

	
private:
	static T* spSingleton;	// 
	Singleton(Singleton const&) = delete;
	void operator=(Singleton const&) = delete;
};

template<typename T> T* Singleton<T>::spSingleton = 0;

#endif

//class Logger
//{
//public:
//
//	/// <summary>
//	/// Get the instance of the Logger object.
//	/// </summary>
//	/// <returns>Logger instance</returns>
//	static Logger& Get()
//	{
//		static Logger instance;
//		return instance;
//	}
//
//	/// <summary>
//	/// Run all neccessary code before being used, this is done because the default constructor is hidden from us
//	/// </summary>
//	void init()
//	{
//		m_vLogOut.resize(0);
//		new Logger;
//	}
//
//	void printLn(std::string log)
//	{
//		m_vLogOut.push_back(log);
//		++logcnt;
//		std::cout << m_vLogOut[logcnt] << std::endl;
//
//	}
//private:
//	Logger() = default;
//	~Logger() = default;
//	std::vector<std::string> m_vLogOut;
//	int logcnt = -1;
//
//};