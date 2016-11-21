%module Cpppy
%include Vector.i

%template(iArray)  std::vector <int>;
%template(fArray)  std::vector <float>;
%template(dArray)  std::vector <double>;
