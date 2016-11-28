%module Cpppy

%include <std_vector.i>

%rename(__mul__) ::operator*;


%{
#include <Random.h>
%}
%include <Random.h>

%include Vector.i
%include Matrix.i

%template(iArray) std::vector<int>;
%template(fArray) std::vector<float>;
%template(dArray) std::vector<double>;
