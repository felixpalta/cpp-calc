#include "../std_lib_facilities.h"
#include "tokenClass.h"

#include "TokenStream.h"

Token_stream::Token_stream()
	:buffer(0),full(false){}

Token Token_stream::getToken(){

	if (full){
		full = false;
		return buffer;
	}

	char c;
	cin >> c;
	if (!cin)
		error("Unable to get token");
	
	switch (c){
	case PLUS:
	case MINUS:
	case MUL:
	case DIV:
	case MODULO:
	case OPEN_BRACE:
	case CLOSE_BRACE:
	case QUIT:
	case PRINT:
		{
			return Token(c);
			break;
		}
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '.':
		{
			cin.putback(c);
			tValType val;
			cin >> val;
			if (!cin)
				error("Unable to get value");
			return Token(NUMBER,val);
			break;
		}
	default:
		error("Unexpected symbol");
		break;
	}
}

void Token_stream::putback(Token t){
	if (full){
		error("putback() in full buffer!");
	}
	buffer = t;
	full = true;
}

void Token_stream::ignore(char c){
	if (full && buffer.kind == c){
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin >> ch){
		if (c == ch) 
			return;
	}
}