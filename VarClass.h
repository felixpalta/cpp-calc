#pragma once

#include "../std_lib_facilities.h"

class Variable {
public:
	string name;
	double value;
	Variable(string s, double v)
		:name(s),value(v){}
};