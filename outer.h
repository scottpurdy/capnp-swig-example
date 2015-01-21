
#ifndef EXAMPLE_OUTER_H
#define EXAMPLE_OUTER_H

#include "proto.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <kj/std/iostream.h>
#include <iostream>

#include "inner.h"

using namespace std;

namespace example {

  class Outer {
    public:
      Outer() {
        fieldA_ = 0.0;
      }
      Outer(float fa, int f1, const char* f2) {
        fieldA_ = fa;
        inner_.setF1(f1);
        inner_.setF2(f2);
      }
      virtual ~Outer() {};

      float getFA() {
        return fieldA_;
      }

      const Inner& getInner() {
        return inner_;
      }

      void write(OuterProto::Builder& proto) const {
        proto.setFieldA(fieldA_);
        auto innerProto = proto.initInner();
        inner_.write(innerProto);
      }

      void write(ofstream& f) const {
        capnp::MallocMessageBuilder message;
        OuterProto::Builder outerProto = message.initRoot<OuterProto>();
        write(outerProto);
        kj::std::StdOutputStream outputStream(f);
        capnp::writeMessage(outputStream, message);
      }

      void write(const char* path) const {
        ofstream f(path);
        write(f);
        f.close();
      }

      void read(OuterProto::Reader& proto) {
        fieldA_ = proto.getFieldA();
        auto innerProto = proto.getInner();
        inner_.read(innerProto);
      }

      void read(ifstream& f) {
        kj::std::StdInputStream inputStream(f);
        capnp::InputStreamMessageReader message(inputStream);
        OuterProto::Reader proto = message.getRoot<OuterProto>();
        read(proto);
      }

      void read(const char* path) {
        ifstream f(path);
        read(f);
        f.close();
      }

    private:
      float fieldA_;
      Inner inner_;
  };

}

#endif // EXAMPLE_OUTER_H
