
#include <string>
#ifndef ERRORLOG_H
#define ERRORLOG_H
namespace preydator{
	class ErrorLog
	{
	public:
		
		static void printError(std::string error);
		~ErrorLog();
	private:
		ErrorLog();

	};
}
#endif
