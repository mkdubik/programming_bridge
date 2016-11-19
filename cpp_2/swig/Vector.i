%{
#include <Vector.h>
%}

%include "std_vector.i"
%include <Vector.h>

%extend Vector {
	Vector __mul__(Vector *other) {
		// Evil pointer magic
		return *self * *other;
	}
};


%template(iArray)  std::vector < int >;
%template(fArray)  std::vector < float >;
%template(dArray)  std::vector < double >;

%template(iVector) Vector<int>;
%template(fVector) Vector<float>;
%template(dVector) Vector<double>;

