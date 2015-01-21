
#ifndef EXAMPLE_INNER_H
#define EXAMPLE_INNER_H

#include <fstream>
#include <iostream>

#include "proto.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <kj/std/iostream.h>

using namespace std;

namespace example {

  class Inner {
    public:
      Inner() {
        f1_ = 0;
        f2_ = "none";
      };
      Inner(int f1, const char* f2) {
        f1_ = f1;
        f2_ = f2;
      }
      virtual ~Inner() {};

      int getF1() {
        return f1_;
      }

      void setF1(int v) {
        f1_ = v;
      }

      const char* getF2() {
        return f2_;
      }

      void setF2(const char* v) {
        f2_ = v;
      }

      void write(InnerProto::Builder& proto) const {
        proto.setF1(f1_);
        proto.setF2(f2_);
      }

      void write(ofstream& f) const {
        capnp::MallocMessageBuilder message;
        InnerProto::Builder innerProto = message.initRoot<InnerProto>();
        write(innerProto);
        kj::std::StdOutputStream outputStream(f);
        capnp::writeMessage(outputStream, message);
      }

      void read(InnerProto::Reader& proto) {
        f1_ = proto.getF1();
        f2_ = proto.getF2().cStr();
      }

      void read(ifstream& f) {
        kj::std::StdInputStream inputStream(f);
        capnp::InputStreamMessageReader message(inputStream);
        InnerProto::Reader proto = message.getRoot<InnerProto>();
        read(proto);
      }
    private:
      int f1_;
      const char* f2_;
  };

}

#endif // EXAMPLE_INNER_H
