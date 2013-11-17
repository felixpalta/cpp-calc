#include "../std_lib_facilities.h"
#include "tokenClass.h"
#include "TokenStream.h"
#include "grammar.h"

Token_stream ts;

int main()
	try {
		while (cin) {
			tValType val = 0.0;
			Token t = ts.getToken();

			if (t.kind == QUIT) break;
			else ts.putback(t);

			val = getExpression();

			t = ts.getToken();

			if (t.kind == QUIT) break;
			if (t.kind == PRINT)
				cout << "= " << val << endl;
			else
				ts.putback(t);
		}
}
catch (exception& errmsg){
	cerr << errmsg.what() << endl;
	keep_window_open();
}
