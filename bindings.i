
%module(package="example") bindings
%{

#include <Python.h>

#include "inner.h"
#include "outer.h"

%}

%include "inner.h"
%include "outer.h"
