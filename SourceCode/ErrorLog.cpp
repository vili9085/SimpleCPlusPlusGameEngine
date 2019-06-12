#include "ErrorLog.h"
#include <iostream>


namespace preydator{
	ErrorLog::ErrorLog()
	{
	}


	ErrorLog::~ErrorLog()
	{
	}

	void ErrorLog::printError(std::string error) {
		std::cout << error << std::endl;

	}
}
