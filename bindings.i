
%module(package="example") bindings
%{

#include <Python.h>

#include "inner.h"
#include "outer.h"

%}

%include "inner.h"
%include "outer.h"

%extend example::Inner
{
  #include "proto.capnp.h"

  inline void write(PyObject* py_builder) const {
    // Get InnerProto::Builder from py_builder object
    //InnerProto::Builder innerProto = ...;
    //self->write(innerProto);
  }

}
