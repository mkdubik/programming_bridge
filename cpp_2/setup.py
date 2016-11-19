#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension


vector_module = Extension('_Cpppy',
                           sources=['swig/Cpppy_wrap.cxx', 'src/Vector.cpp'],
                           )

setup (name = 'Cpppy',
       version = '0.1',
       author      = "SWIG Docs",
       description = """Simple swig example from docs""",
       ext_modules = [vector_module],
       py_modules = ["Cpppy"],
       )