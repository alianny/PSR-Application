#pragma once
#include <string>

public class CallBackClass
{
private:
	static std::string textboxUpdate;
public:
	//Constructor 
	CallBackClass(){};

	/*
	 * Arguments:
	 *
	 *   unused - Ignored in this case, see the documentation for sqlite3_exec
	 *    count - The number of columns in the result set
	 *     data - The row's data
	 *  columns - The column names
	 */
	static int callback_Tester(void *unused, int count, char **argvdata, char **columns);
	static inline std::string getTextUpdate(){ return textboxUpdate; };
};