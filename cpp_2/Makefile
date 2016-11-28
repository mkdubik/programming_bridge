all:
	$ @mkdir -p build/
	$ swig -Wall -c++ -python -Iinclude/ -outdir build/ swig/Cpppy.i
	$ python setup.py build_ext --include include/ --build-lib build/
	$ @mv swig/Cpppy_wrap.cxx build/
	$ @mv build/Cpppy.py .
	$ @mv build/_Cpppy.so .

clean:
	rm -f __init__.pyc
	rm -f Cpppy.py
	rm -f Cpppy.pyc
	rm -f _Cpppy.so
	rm -rf build
