#include "stdafx.h"
#include "SQLCallBack.h"
#include <string>

using namespace System::Diagnostics;

std::string CallBackClass::textboxUpdate ="";

int CallBackClass::callback_Tester(void *ID, int count, char **data, char **columns)
{
	std::string test = *((std::string *)ID);
	Debug::WriteLine(gcnew System::String(test.c_str()));
	textboxUpdate = "\nNumber of Columns found = " + std::to_string(count);
	for(int i = 0; i < count; i++)
		textboxUpdate += std::to_string(i) + "\nData = " + data[i] + "Column? " + columns[i];
	return 1;
}

