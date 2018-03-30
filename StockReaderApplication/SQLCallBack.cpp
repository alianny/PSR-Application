#pragma once
#include "stdafx.h"
#include "SQLCallBack.h"
#include <string>

using namespace System::Diagnostics;

std::string CallBackClass::textboxUpdate ="";

int CallBackClass::callback_Tester(void *ID, int count, char **data, char **columns)
{
	textboxUpdate += "\n----------------------------------";
	for(int i = 0; i < count; i++)
		textboxUpdate += "\n" + std::to_string(i+1) + ": " + columns[i] +" Value: " + data[i] ;
	return 0;
}

