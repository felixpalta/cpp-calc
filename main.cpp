#include "../std_lib_facilities.h"
#include "tokenClass.h"
#include "TokenStream.h"


int main()
try {


	tValType lval = 0;
	tValType rval;
	tKindType op;

	Token t;
	t.kind = NUMBER;
	t.value = 0;

	cin >> lval;

	if (!cin)
	{
		error("no first operand");
	}
	while (cin >> op){
		switch (op){
		case SUM:
		case SUB:
		case DIV:
		case MUL:
			cin >> rval;
			if (!cin){
				error("No last operand");
			}
			break;
		default:
			cout << "Result: " << lval << endl;
			return 0;
		}

		switch (op){
		case SUM:

			lval += rval;
			break;
		case SUB:
			lval -= rval;
			break;
		case MUL:
			lval *= rval;
			break;
		case DIV:
			if (rval == 0.0)
				error("Division by zero!");
			lval /= rval;
			break;
		default:
			error("how did I get here?");
			return 1;
		}
	}

	cout << "Result: " << lval << endl;	 // screw the last operand
}

catch (exception& errmsg){
	cerr << errmsg.what() << endl;
	keep_window_open();
}
