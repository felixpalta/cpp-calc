#include "../std_lib_facilities.h"
#include "TokenStream.h"


Token getToken(){
	char c;
	cin >> c;
	if (!cin)
		error("Unable to get token");
	
	switch (c){
	case SUM:
	case SUB:
	case MUL:
	case DIV:
	case MODULO:
	case OPEN_BRACE:
	case CLOSE_BRACE:
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
