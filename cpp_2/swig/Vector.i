%{
#include <Vector.h>
%}

%include "std_vector.i"
%include <std_string.i>
%include <Vector.h>


%extend Vector {
	//Vector ones(unsigned int size) {
	//	return (*($self)).ones(size);
	//}

	T __getitem__(unsigned int ix) {
		return (*($self))[ix];
	}

	void __setitem__(unsigned int ix, T t) {
		(*($self))[ix] = t;
	}

	std::string __str__() {
		return (*($self)).to_string();
	}

};

%rename(__mul__) Vector::operator*;

%template(iVector) Vector<int>;
%template(fVector) Vector<float>;
%template(dVector) Vector<double>;
