#pragma once
#include "../std_lib_facilities.h"
#include "VarClass.h"

extern vector<Variable> var_table;

double get_value(string s){
	for (int i = 0; i < var_table.size(); ++i)
	{
		if (var_table[i].name == s)
		{
			return var_table[i].value;
		}
	}
	error("Undefined variable",s);
}

void set_value(string s,double val){
	for (int i = 0; i < var_table.size(); ++i){
		if (var_table[i].name == s){
			var_table[i].value == val;
			return;
		}
	}
	error("Undefined variable", s);
	return;
}