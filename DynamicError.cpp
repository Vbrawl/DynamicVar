#include "DynamicError.hpp"

unsigned short DErrno = ERROR_CODE_SUCCESS;

using std::cout;
using std::endl;


bool hasError() {
	return DErrno != ERROR_CODE_SUCCESS;
}

const char* getDErrorString() {
	const char* str = NULL;
	switch(DErrno) {
	case ERROR_CODE_WRONG_TYPE:
		str = "Attempted to perform an action with invalid argument type";
		break;
	case ERROR_CODE_OUT_OF_MEMORY:
		str = "Memory allocation failed(OUT_OF_MEMORY)";
		break;
	case ERROR_CODE_IS_VOID:
		str = "Attempted to perform an action on/with a void argument type";
		break;

	case ERROR_CODE_SUCCESS:
	default:
		str = "There was no error";
	}
	return str;
}


void PDError(const char* str) {
	cout << str << getDErrorString() << endl;
	cout << "SHOWN\n";
}
