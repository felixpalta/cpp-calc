#pragma once
#include "../std_lib_facilities.h"
#include "common_types.h"

//class
class Token {
public:
	tKindType kind;
	tValType value;
	string name;
//constructors
	Token(tKindType ch)
		:kind(ch),value(0){}

	Token(tKindType ch,tValType val)
		:kind(ch),value(val){}
	Token(tKindType ch,string s)
		:kind(ch),name(s){}

	Token()
	:kind(0),value(0){}
};