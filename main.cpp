#include "../std_lib_facilities.h"
#include "common_types.h"
#include "tokenClass.h"
#include "TokenStream.h"
#include "grammar.h"

Token_stream ts;

const String PROMPT = "> ";	//not gonna use until I learn how to backspace a character from cout
const String RESULT = "= ";

int main()
	try {
		cout << "A simple calculator.\n"
				"Type mathematical expressions, terminate them with a '" << PRINT << "' symbol and hit Enter.\n"
				"Examples:\n"
				"\t1 + 1;\n"
				"\t(3 + (4*2)%12) + 1;\n"
				"Allowed operators are: +,-,/,%,*,().\n"
				"To declare a variable type: " << DECLKEY << " variable_name = initial_value;\n"
				"Example:\n"
				"\t" << DECLKEY << " var = 3.5;\n"
				"Declared variable can be then used in expressions as:\n"
				"\t(var + 1)*2\n"
				"In case of an error type a '" << PRINT << "' symbol, then type expressions as usual.\n"
				"Type '" << QUIT << "', '" << EXITKEY1 << "' or '" << EXITKEY2 << "' to quit." 
				<< endl;
		while (cin) 
		try {
			cout << PROMPT;
			Token t = ts.getToken();
			while (t.kind == PRINT) t = ts.getToken();	//eat extras
			if (t.kind == QUIT){
				//keep_window_open();
				return 0;
			}
			ts.putback(t);
			cout << RESULT << getStatement() << endl;

		}

		catch (exception& errmsg){
			cerr << errmsg.what() << endl;
			ts.ignore(PRINT);
		}

		//keep_window_open();
		return 0;
}
catch (exception& errmsg){
	cerr << errmsg.what() << endl;
	keep_window_open("~~");
}
