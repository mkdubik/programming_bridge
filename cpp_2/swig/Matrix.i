%ignore Matrix::operator[];

%{
#include <Matrix.h>
%}

%include <std_string.i>
%include <Matrix.h>

%extend Matrix {
	Vector<T> __getitem__(unsigned int ix) {
		return (*($self))[ix];
	}

	void __setitem__(unsigned int ix, Vector<T> t) {
		(*($self))[ix] = t;
	}

	std::string __str__() {
		return (*($self)).to_string();
	}

	int __len__() {
		return (*($self)).size()[0];
	}

};

%template(iMatrix) Matrix<int>;
%template(fMatrix) Matrix<float>;
%template(dMatrix) Matrix<double>;
