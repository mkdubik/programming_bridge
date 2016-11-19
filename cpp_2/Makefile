all:
	$ mkdir -p build/
	$ swig -Wall -c++ -python -Iinclude/ -outdir build/ swig/Cpppy.i
	$ python setup.py build_ext --include include/ --build-lib build/
	$ mv swig/*.cxx build/
