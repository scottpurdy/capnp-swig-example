
%module(package="example") bindings
%{

#include <Python.h>

#include "swig_capnp.h"

#include "proto.capnp.h"

#include "inner.h"
#include "outer.h"

%}

%include "inner.h"
%include "outer.h"

%extend example::Inner
{

  inline void write(PyObject* pyBuilder) const
  {
    InnerProto::Builder innerProto = getBuilder<InnerProto>(pyBuilder);
    self->write(innerProto);
  }

  inline void read(PyObject* pyReader) {
    InnerProto::Reader innerProto = getReader<InnerProto>(pyReader);
    self->read(innerProto);
  }

}
