
%module(package="example") bindings
%{

#include <Python.h>

#include <capnp/dynamic.h>
#include <capnp/message.h>

#include "inner.h"
#include "outer.h"

// Not used currently
struct pycapnp_MessageBuilder {
  PyObject_HEAD
  void *__pyx_vtab;
  ::capnp::MessageBuilder *thisptr;
};

struct pycapnp_DynamicStructBuilder {
  PyObject_HEAD
  void *__pyx_vtab;
   ::capnp::DynamicStruct::Builder thisptr;
  PyObject *_parent;
  int is_root;
  int _is_written;
  PyObject *_schema;
};

%}

%include "inner.h"
%include "outer.h"

%extend example::Inner
{
  #include "proto.capnp.h"

  inline void write(PyObject* pyBuilder) const {
    // Get InnerProto::Builder from pyBuilder object
    //pycapnp_DynamicStructBuilder* dynamicStruct = (pycapnp_DynamicStructBuilder*)pyBuilder;
    //::capnp::DynamicStruct::Builder* builder = &dynamicStruct->thisptr;
    //InnerProto::Builder* innerProto = (InnerProto::Builder*)builder;
    //self->write(*innerProto);
  }

}
