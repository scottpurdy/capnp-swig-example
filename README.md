# Example Hybrid Python/C++ Application with Cap'n Proto

This project is to illustrate how to use Cap'n Proto in a Python/C++/SWIG
environment where you can pass Cap'n Proto objects between Python and C++
code.

## Install

I just hacked this together so you may need to modify the Makefile path for
the Python includes. You must also have the latest Cap'n Proto installed.
To install, run:

```
make
```

This will build the C++ test binary, generate SWIG bindings for the `outer.h`
and `inner.h`, and build a shared library with Python wrapper.

## What Works

You can currently run the following:

```
# Run a simple test of the pure-C++ code
./test

# Run a simple test of the pure-Python code
./example/test_python.py

# Run a simple test of the C++ bindings. This test is in Python but uses
# the C++ Outer class
./example/test_bindings.py

# Run a hybrid Python/C++ test. This uses a Python Outer class with the
# SWIGed C++ Inner class. It creates a pycapnp OuterProto and passes the
# InnerProto struct to the C++ code.
# THIS DOESN'T WORK YET - need to figure out how to retrieve C++
# InnerProto::Builder and Reader from the PyObject generated by Cython
./example/test_hybrid.py
```