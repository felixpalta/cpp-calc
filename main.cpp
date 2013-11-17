#include "../std_lib_facilities.h"
#include "tokenClass.h"
#include "TokenStream.h"
#include "grammar.h"


int main()
	try {
		while (cin)
			cout << "= " << getExpression() << '\n';
		keep_window_open("~0");
}
catch (exception& errmsg){
	cerr << errmsg.what() << endl;
	keep_window_open();
}
