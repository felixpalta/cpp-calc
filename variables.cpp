#include "../std_lib_facilities.h"
#include "common_types.h"
#include "VarClass.h"
#include "variables.h"

vector<Variable> var_table;

double get_value(string s){
	for (int i = 0; (unsigned)i < var_table.size(); ++i)
	{
		if (var_table[i].name == s)
		{
			return var_table[i].value;
		}
	}
	error("Undefined variable: ",s);
}

void set_value(string s,double val){
	for (int i = 0; (unsigned) i < var_table.size(); ++i){
		if (var_table[i].name == s){
			var_table[i].value = val;
			return;
		}
	}
	error("Undefined variable: ", s);
	return;
}

bool is_declared(string s){
	for (int i = 0; (unsigned) i < var_table.size(); ++i){
		if (var_table[i].name == s)
			return true;
	}
	return false;
}

tValType add_variable(string s,tValType val){
	if (is_declared(s)) error(s, " is declared");
	var_table.push_back(Variable(s,val));
	return val;
}