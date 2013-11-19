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
