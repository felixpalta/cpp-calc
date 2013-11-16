#include "../std_lib_facilities.h"
#include "TokenStream.h"



double getExpression(){
	double left = getTerm();
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

double getTerm(){
	return 0.0;
}

double getPrimary(){
	return 0.0;
}

Token getToken(){
	Token t(0,0);
	return t;
}