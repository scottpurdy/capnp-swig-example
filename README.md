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

## Running It

The tests show all the different scenarios:

```
# Run a simple test of the pure-C++ code
./test

# Run a simple test of the pure-Python code
./example/test_python.py

# Run a simple test of the C++ bindings. This test is in Python but uses
# the C++ Outer class (which then uses the C++ Inner class).
./example/test_bindings.py

# Run a hybrid Python/C++ test. This uses a Python Outer class with the
# SWIGed C++ Inner class. It creates a pycapnp OuterProto and passes the
# InnerProto struct to the C++ code. Conversion from the pycapnp struct
# to the appropriate C++ class happens in the bindings.i file.
./example/test_hybrid.py
```
