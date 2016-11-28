#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension


cpppy_module = Extension('_Cpppy',
                           sources=['swig/Cpppy_wrap.cxx'],
                           swig_opts=['-c++']
                           )

setup (name = 'Cpppy',
       version = '0.1',
       author      = "SWIG Docs",
       description = """Simple swig example from docs""",
       ext_modules = [cpppy_module],
       py_modules = ["Cpppy"],
       )