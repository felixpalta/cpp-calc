#include "../std_lib_facilities.h"
#include "TokenStream.h"



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

			if (right == 0)
				error("Divide by zero!");
			left /= right;
			break;
			}
		case MODULO:{
			tValType right = getPrimary();

			if (right == 0)
				error("Divide by zero!");
			int iLeft = narrow_cast<int>(left);
			iLeft %= narrow_cast<int>(right);
			left = iLeft;
			break;
			}

		}
	}
}

tValType getPrimary(){
	return 0.0;
}

Token getToken(){
	Token t(0,0);
	return t;
}