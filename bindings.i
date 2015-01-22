
%module(package="example") bindings
%{

#include <Python.h>

#include <capnp/any.h>
#include <capnp/dynamic.h>
#include <capnp/message.h>

#include "proto.capnp.h"

#include "inner.h"
#include "outer.h"

struct pycapnp_DynamicStructBuilder {
  PyObject_HEAD
  void *__pyx_vtab;
   ::capnp::DynamicStruct::Builder thisptr;
  PyObject *_parent;
  int is_root;
  int _is_written;
  PyObject *_schema;
};

struct pycapnp__DynamicStructReader {
  PyObject_HEAD
  void *__pyx_vtab;
   ::capnp::DynamicStruct::Reader thisptr;
  PyObject *_parent;
  int is_root;
  PyObject *_obj_to_pin;
  PyObject *_schema;
};

%}

%include "inner.h"
%include "outer.h"

%extend example::Inner
{

  inline void write(PyObject* pyBuilder) const {
    pycapnp_DynamicStructBuilder* dynamicStruct = (pycapnp_DynamicStructBuilder*)pyBuilder;
    ::capnp::DynamicStruct::Builder& builder = dynamicStruct->thisptr;
    InnerProto::Builder innerProto = builder.as<::capnp::AnyStruct>().as<InnerProto>();
    self->write(innerProto);
  }

  inline void read(PyObject* pyReader) {
    pycapnp__DynamicStructReader * dynamicStruct = (pycapnp__DynamicStructReader*)pyReader;
    ::capnp::DynamicStruct::Reader& reader = dynamicStruct->thisptr;
    InnerProto::Reader innerProto = reader.as<::capnp::AnyStruct>().as<InnerProto>();
    self->read(innerProto);
  }

}
