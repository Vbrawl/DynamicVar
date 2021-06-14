#ifndef DYNAMIC_ERROR
#define DYNAMIC_ERROR 1


#include <iostream>


static constexpr unsigned short ERROR_CODE_SUCCESS = 0;
static constexpr unsigned short ERROR_CODE_WRONG_TYPE = 1;
static constexpr unsigned short ERROR_CODE_OUT_OF_MEMORY = 2;
static constexpr unsigned short ERROR_CODE_IS_VOID = 3;




extern unsigned short DErrno;
bool hasError();
void PDError(const char* str = "");
const char* getDErrorString();



#endif // DYNAMIC_ERROR
