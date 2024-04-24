#include<iostream>
#include"Framework.h"

int main()
{
	new TLogger; // Create instance of TLogger singleton class

	Logger SimpleLogger;	// Logger class instance for parsing between modules

	Framework* pFramework = new Framework; // Create framework instance for demonstration purposes.



	std::cout << ("Program Entry Point");

	while (pFramework->getExitStatus() == false)
	{
		// Un-Comment the one you want to see

		//pFramework->updateSingletonsLoop();				// Singleton Approach demonstration of a logger class in use.
		pFramework->updateNamspaceLoop();					// Alternative demonstration of the Namespace Approach.
		//pFramework->updateParsedLoop(&SimpleLogger);		// Alternative demonstration of the Passing Approach.

	}
	
	return 0;
}




