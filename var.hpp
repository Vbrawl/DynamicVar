#ifndef DYNAMIC_VAR
#define DYNAMIC_VAR


#include <cstddef>
#include <cstdlib>
#include <cstring>
#include "DynamicError.hpp"
#include "DynamicObject.hpp"


static constexpr unsigned short VOID_TYPE = 0;
static constexpr unsigned short BOOL_TYPE = 1;
static constexpr unsigned short CHAR_TYPE = 2;
static constexpr unsigned short INTEGER_TYPE = 3;
static constexpr unsigned short LONG_TYPE = 4;
static constexpr unsigned short SHORT_TYPE = 5;
static constexpr unsigned short STRING_TYPE = 6;
static constexpr unsigned short OBJECT_TYPE = 7;




namespace Dynamic {

	class var {
	private:
		unsigned short type = VOID_TYPE;

		bool b_var = false;
		char c_var = '\0';
		int i_var = 0;
		long l_var = 0;
		short short_var = 0;
		char* string_var = NULL;
		DynamicObject* object_var;

	public:
		/*CONSTRUCTORS*/
		var();
		var(bool v);
		var(const char v);
		var(const int v);
		var(const long v);
		var(const short v);
		var(const char* v);
		var(DynamicObject* obj);


		/*GetType*/
		unsigned short getType() const;


		/*Getters*/
		bool getBool() const;
		char getChar() const;
		int getInteger() const;
		long getLongInt() const;
		short getShortInt() const;
		const char* getString() const;
		DynamicObject* getObject() const;


		/*Operators*/
		/*+*/
		var operator+(const char& v); // error if type != CHAR_TYPE && type != STRING_TYPE || There is not enough memory
		var operator+(const int& v); // error if type is not 1 of the following: INTEGER_TYPE, LONG_TYPE, SHORT_TYPE, CHAR_TYPE
		var operator+(const long& v);
		var operator+(const short& v);
		var operator+(const char*& v); // error if type != STRING_TYPE || There is not enough memory
		var operator+(const var& v);

		/*-*/
		var operator-(const char& v);
		var operator-(const int& v);
		var operator-(const long& v);
		var operator-(const short& v);
		var operator-(const var& v);

		/*=*/
		var operator=(const char& v);
		var operator=(const int& v);
		var operator=(const bool& v);
		var operator=(const long& v);
		var operator=(const short& v);
		var operator=(const char*& v);
		var operator=(DynamicObject& v);
		void makeVoid();


		/*DESTRUCTOR*/
		~var();
	};



}




#endif // DYNAMIC_VAR
