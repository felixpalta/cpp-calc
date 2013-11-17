#pragma once

#include "tokenClass.h"

const tKindType NUMBER = '8';
const tKindType PLUS = '+';
const tKindType MINUS = '-';
const tKindType MUL = '*';
const tKindType DIV = '/';
const tKindType MODULO = '%';
const tKindType OPEN_BRACE = '(';
const tKindType CLOSE_BRACE = ')';
const tKindType QUIT = 'q';
const tKindType PRINT = ';';

class Token_stream {
public:
	Token_stream();
	Token getToken();
	void putback(Token t);
	void ignore(char c);
private:
	Token buffer;
	bool full;
};