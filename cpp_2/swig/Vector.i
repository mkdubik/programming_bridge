%ignore Vector::operator[];

%{
#include <Vector.h>
%}

%include <std_string.i>
%include <Vector.h>

%extend Vector {
	T __getitem__(unsigned int ix) {
		return (*($self))[ix];
	}

	void __setitem__(unsigned int ix, T t) {
		(*($self))[ix] = t;
	}

	std::string __str__() {
		return (*($self)).to_string();
	}

	int __len__() {
		return (*($self)).size();
	}

};

%template(iVector) Vector<int>;
%template(fVector) Vector<float>;
%template(dVector) Vector<double>;
