#pragma once
#include "../std_lib_facilities.h"
#include "common_types.h"
#include "VarClass.h"

extern vector<Variable> var_table;

tValType get_value(string s);
void set_value(string s, tValType val);
bool is_declared(string s);
tValType add_variable(string s,tValType val);