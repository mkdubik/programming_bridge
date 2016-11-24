%{
#include <Matrix.h>
%}

%include "std_vector.i"
%include <std_string.i>
%include <Matrix.h>

%rename(__mul__) Matrix::operator*;

%template(iMatrix) Matrix<int>;
%template(fMatrix) Matrix<float>;
%template(dMatrix) Matrix<double>;
