#pragma once

#include "../std_lib_facilities.h"
#include "common_types.h"
class Variable {
public:
	string name;
	tValType value;
	Variable(string s, tValType v)
		:name(s),value(v){}
};