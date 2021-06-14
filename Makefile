OutputLibName = libDynamicVar.so


cpp_files = var.cpp\
	DynamicError.cpp\
	DynamicObject.cpp


hpp_files = var.hpp\
	DynamicError.hpp\
	DynamicObject.hpp



SharedLib = g++ -fPIC -shared
D_SharedLib = $(SharedLib) -g




build: $(cpp_files) $(hpp_files)
	$(SharedLib) $(cpp_files) -o $(outName)


debug: $(cpp_files) $(hpp_files)
	$(D_SharedLib) $(cpp_files) -o $(outName)
