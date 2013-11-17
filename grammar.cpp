#include "../std_lib_facilities.h"
#include "tokenClass.h"
#include "TokenStream.h"

#include "grammar.h"

tValType getExpression(){
	tValType left = getTerm();
	Token t = getToken();
	while (true) {
		switch (t.kind){
		case SUM:
			left += getTerm();
			t = getToken();
			break;
		case SUB:
			left -= getTerm();
			t = getToken();
			break;
		default:
			return left;
			break;
		}
	}
}

tValType getTerm(){
	tValType left = getPrimary();
	Token t = getToken();
	while (true)
	{
		switch (t.kind){
		case MUL:
			left *= getPrimary();

			t = getToken();
			break;
		case DIV:{
			tValType right = getPrimary();
			if (right == 0.0)
				error("Divide by zero!");
			left /= right;

			t = getToken();
			break;
				 }
		case MODULO:{
			tValType right = getPrimary();
			if (right == 0.0)
				error("Divide by zero!");
			int iLeft = narrow_cast<int>(left);
			iLeft %= narrow_cast<int>(right);
			left = iLeft;

			t = getToken();
			break;
					}
		default:
			return left;

		}
	}
}

tValType getPrimary(){
	Token t = getToken();
	switch (t.kind){
	case OPEN_BRACE:
		{
			tValType d = getExpression();
			t = getToken();
			if (t.kind != CLOSE_BRACE)
				error("Closing brace expected");
			return d;
		}
	case NUMBER:
		return t.value;
	default:
		error("Primary expected");
		return ERR_VALUE;	// not needed, because error() terminates the program
	}
}
