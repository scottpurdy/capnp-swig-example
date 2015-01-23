
#ifndef SWIG_CAPNP_H
#define SWIG_CAPNP_H

#include <Python.h>

#include <capnp/any.h>
#include <capnp/dynamic.h>
#include <capnp/message.h>
#include <capnp/schema-parser.h>

struct pycapnp_SchemaParser {
  PyObject_HEAD
  void *__pyx_vtab;
   ::capnp::SchemaParser *thisptr;
  PyObject *modules_by_id;
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

struct pycapnp_DynamicStructReader {
  PyObject_HEAD
  void *__pyx_vtab;
   ::capnp::DynamicStruct::Reader thisptr;
  PyObject *_parent;
  int is_root;
  PyObject *_obj_to_pin;
  PyObject *_schema;
};

template<class T>
typename T::Builder getBuilder(PyObject* pyBuilder)
{
  PyObject* capnpModule = PyImport_AddModule("capnp.lib.capnp");
  PyObject* pySchemaParser = PyObject_GetAttrString(capnpModule,
                                                    "_global_schema_parser");
  pycapnp_SchemaParser* schemaParser = (pycapnp_SchemaParser*)pySchemaParser;
  schemaParser->thisptr->loadCompiledTypeAndDependencies<T>();

  pycapnp_DynamicStructBuilder* dynamicStruct = (pycapnp_DynamicStructBuilder*)pyBuilder;
  ::capnp::DynamicStruct::Builder& builder = dynamicStruct->thisptr;
  typename T::Builder proto = builder.as<T>();
  return proto;
}

template<class T>
typename T::Reader getReader(PyObject* pyReader)
{
  PyObject* capnpModule = PyImport_AddModule("capnp.lib.capnp");
  PyObject* pySchemaParser = PyObject_GetAttrString(capnpModule,
                                                    "_global_schema_parser");
  pycapnp_SchemaParser* schemaParser = (pycapnp_SchemaParser*)pySchemaParser;
  schemaParser->thisptr->loadCompiledTypeAndDependencies<T>();

  pycapnp_DynamicStructReader* dynamicStruct = (pycapnp_DynamicStructReader*)pyReader;
  ::capnp::DynamicStruct::Reader& reader = dynamicStruct->thisptr;
  typename T::Reader proto = reader.as<T>();
  return proto;
}

#endif // SWIG_CAPNP_H
