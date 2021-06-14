#ifndef DYNAMIC_OBJECT
#define DYNAMIC_OBJECT


namespace Dynamic {

	class DynamicObject {
	private:
		static constexpr const char* className = "DynamicObject";
	public:
		virtual const char* WhatObjectName() const;
	};
};

#endif // DYNAMIC_OBJECT
