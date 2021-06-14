#include "var.hpp"


using std::__cxx11::to_string;


namespace Dynamic {


	/*CONSTRUCTORS*/
	var::var(){
		type = VOID_TYPE;
		this->makeVoid();
	}

	var::var(bool v) {
		type = BOOL_TYPE;
		b_var = v;
	}


	var::var(const char v) {
		type = CHAR_TYPE;
		c_var = v;
	}

	var::var(const int v) {
		type = INTEGER_TYPE;
		i_var = v;
	}

	var::var(const long v) {
		type = LONG_TYPE;
		l_var = v;
	}

	var::var(const short v) {
		type = SHORT_TYPE;
		short_var = v;
	}

	var::var(const char* v) {
		type = STRING_TYPE;
		string_var = strdup(v);
	}

	var::var(DynamicObject* v) {
		type = OBJECT_TYPE;
		object_var = v;
	}



	/*GetType*/
	unsigned short var::getType() const {
		DErrno = ERROR_CODE_SUCCESS;
		return type;
	}



	/*Getters*/
	bool var::getBool() const {
		if(type == BOOL_TYPE) {
			DErrno = ERROR_CODE_SUCCESS;
			return b_var;
		}
		DErrno = ERROR_CODE_WRONG_TYPE;
		return false;
	}

	char var::getChar() const {
		if(type == CHAR_TYPE) {
			DErrno = ERROR_CODE_SUCCESS;
			return c_var;
		}
		DErrno = ERROR_CODE_WRONG_TYPE;
		return '\0';
	}

	int var::getInteger() const {
		if(type == INTEGER_TYPE) {
			DErrno = ERROR_CODE_SUCCESS;
			return i_var;
		}
		DErrno = ERROR_CODE_WRONG_TYPE;
		return 0;
	}

	long var::getLongInt() const {
		if(type == LONG_TYPE) {
			DErrno = ERROR_CODE_SUCCESS;
			return l_var;
		}
		DErrno = ERROR_CODE_WRONG_TYPE;
		return 0;
	}

	short var::getShortInt() const {
		if(type == SHORT_TYPE) {
			DErrno = ERROR_CODE_SUCCESS;
			return short_var;
		}
		DErrno = ERROR_CODE_WRONG_TYPE;
		return 0;
	}

	const char* var::getString() const {
		if(type == STRING_TYPE) {
			DErrno = ERROR_CODE_SUCCESS;
			return (const char*)string_var;
		}
		DErrno = ERROR_CODE_WRONG_TYPE;
		return NULL;
	}

	DynamicObject* var::getObject() const {
		if(type == OBJECT_TYPE) {
			DErrno = ERROR_CODE_SUCCESS;
			return object_var;
		}
		DErrno = ERROR_CODE_WRONG_TYPE;
		return NULL;
	}





	/*Operators*/
	/*+*/
	var var::operator+(const char& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(type) {
		case CHAR_TYPE:
			c_var += v;
			break;
		case STRING_TYPE:
			{
				size_t len = string_var?strlen(string_var):0;
				char* temp_s = (char*)realloc(string_var, len+2);
				if(!temp_s) {
					DErrno = ERROR_CODE_OUT_OF_MEMORY;
				} else {
					string_var = temp_s;
					string_var[len] = v;
					string_var[len+1] = '\0';
				}
				break;
			}
		default:
			DErrno = ERROR_CODE_WRONG_TYPE;
		}
		return (*this);
	}

	var var::operator+(const int& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(type) {
		case INTEGER_TYPE:
			i_var += v;
			break;
		case LONG_TYPE:
			l_var += v;
			break;
		case SHORT_TYPE:
			short_var += v;
			break;
		case CHAR_TYPE:
			c_var += v;
			break;
		case STRING_TYPE:
			(*this)+to_string(v).c_str();
			break;
		default:
			DErrno = ERROR_CODE_WRONG_TYPE;
		}
		return (*this);
	}

	var var::operator+(const long& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(type) {
		case INTEGER_TYPE:
			i_var += v;
			break;
		case LONG_TYPE:
			l_var += v;
			break;
		case SHORT_TYPE:
			short_var += v;
			break;
		case CHAR_TYPE:
			c_var += v;
			break;
		case STRING_TYPE:
			(*this)+to_string(v).c_str();
			break;
		default:
			DErrno = ERROR_CODE_WRONG_TYPE;
		}
		return (*this);
	}

	var var::operator+(const short& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(type) {
		case SHORT_TYPE:
			short_var += v;
			break;
		case INTEGER_TYPE:
			i_var += v;
			break;
		case LONG_TYPE:
			l_var += v;
			break;
		case CHAR_TYPE:
			c_var += v;
			break;
		case STRING_TYPE:
			(*this)+to_string(v).c_str();
			break;
		default:
			DErrno = ERROR_CODE_WRONG_TYPE;
		}
		return (*this);
	}

	var var::operator+(const char*& v) {
		DErrno = ERROR_CODE_SUCCESS;
		if(type == STRING_TYPE) {
			size_t mlen = string_var?strlen(string_var):0;
			size_t olen = v?strlen(v):0;

			char* temp_s = (char*)realloc((void*)string_var, (mlen + olen)+1);
			if(!temp_s) {
				DErrno = ERROR_CODE_OUT_OF_MEMORY;
			} else {
				string_var = temp_s;
				for(size_t i = 0; i < olen; i++) {
					string_var[mlen+i] = v[i];
				}
				string_var[mlen+olen] = '\0';
			}
		} else {
			DErrno = ERROR_CODE_WRONG_TYPE;
		}
		return (*this);
	}

	var var::operator+(const var& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(v.getType()) {
		case CHAR_TYPE:
			(*this)+v.getChar();
			break;
		case INTEGER_TYPE:
			(*this)+v.getInteger();
			break;
		case LONG_TYPE:
			(*this)+v.getLongInt();
			break;
		case SHORT_TYPE:
			(*this)+v.getShortInt();
			break;
		case STRING_TYPE:
			(*this)+v.getString();
			break;
		case BOOL_TYPE:
			DErrno = ERROR_CODE_WRONG_TYPE;
			break;
		default:
			DErrno = ERROR_CODE_IS_VOID;
		}

		return (*this);
	}



	/*-*/
	var var::operator-(const char& v) {
		DErrno = ERROR_CODE_SUCCESS;
		if(type == CHAR_TYPE) c_var -= v;
		else DErrno = ERROR_CODE_WRONG_TYPE;
		return (*this);
	}

	var var::operator-(const int& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(type) {
		case INTEGER_TYPE:
			i_var -= v;
			break;
		case LONG_TYPE:
			l_var -= v;
			break;
		case SHORT_TYPE:
			short_var -= v;
			break;
		case CHAR_TYPE:
			c_var -= v;
			break;
		default:
			DErrno = ERROR_CODE_WRONG_TYPE;
		}
		return (*this);
	}

	var var::operator-(const long& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(type) {
		case INTEGER_TYPE:
			i_var -= v;
			break;
		case LONG_TYPE:
			l_var -= v;
			break;
		case SHORT_TYPE:
			short_var -= v;
			break;
		case CHAR_TYPE:
			c_var -= v;
			break;
		default:
			DErrno = ERROR_CODE_WRONG_TYPE;
		}

		return (*this);
	}

	var var::operator-(const short& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(type) {
		case INTEGER_TYPE:
			i_var -= v;
			break;
		case LONG_TYPE:
			l_var -= v;
			break;
		case SHORT_TYPE:
			short_var -= v;
			break;
		case CHAR_TYPE:
			c_var -= v;
			break;
		default:
			DErrno = ERROR_CODE_WRONG_TYPE;
		}
		return (*this);
	}

	var var::operator-(const var& v) {
		DErrno = ERROR_CODE_SUCCESS;
		switch(v.getType()) {
		case CHAR_TYPE:
			(*this) - v.getChar();
			break;
		case INTEGER_TYPE:
			(*this) - v.getInteger();
			break;
		case LONG_TYPE:
			(*this) - v.getLongInt();
			break;
		case SHORT_TYPE:
			(*this) - v.getShortInt();
			break;
		default:
			DErrno = ERROR_CODE_WRONG_TYPE;
		}
		return (*this);
	}


	/*=*/
	var var::operator=(const char& v) {
		type = CHAR_TYPE;
		c_var = v;
		DErrno = ERROR_CODE_SUCCESS;
		return (*this);
	}

	var var::operator=(const int& v) {
		type = INTEGER_TYPE;
		i_var = v;
		DErrno = ERROR_CODE_SUCCESS;
		return (*this);
	}

	var var::operator=(const bool& v) {
		type = BOOL_TYPE;
		b_var = v;
		DErrno = ERROR_CODE_SUCCESS;
		return (*this);
	}

	var var::operator=(const long& v) {
		type = LONG_TYPE;
		l_var = v;
		DErrno = ERROR_CODE_SUCCESS;
		return (*this);
	}


	var var::operator=(const short& v) {
		type = SHORT_TYPE;
		short_var = v;
		DErrno = ERROR_CODE_SUCCESS;
		return (*this);
	}

	var var::operator=(const char*& v) {
		type = STRING_TYPE;
		if(string_var) {
			free(string_var);
			string_var = NULL;
		}
		if(!v) return (*this);

		string_var = strdup(v);
		DErrno = string_var?ERROR_CODE_SUCCESS:ERROR_CODE_OUT_OF_MEMORY;
		return (*this);
	}

	void var::makeVoid() {
		type = VOID_TYPE;
	}

	var var::operator=(DynamicObject& v) {
		type = OBJECT_TYPE;
		object_var = &v;
		return (*this);
	}


	/*DESTRUCTOR*/
	var::~var() {
		free((void*)string_var);
	}

}
