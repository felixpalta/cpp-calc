#pragma once

//types
typedef double tValType;
typedef char tKindType;

//constants, character literals

extern const tKindType NUMBER;

//class
class Token {
public:
	tKindType kind;
	tValType value;
//constructors
	Token(tKindType ch)
		:kind(ch),value(0){}

	Token(tKindType ch,tValType val)
		:kind(ch),value(val){}

	Token()
	:kind(0),value(0){}
};