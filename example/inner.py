
import capnp

from example.proto_capnp import InnerProto

class Inner(object):

  def __init__(self, f1=0, f2="none"):
    self.f1 = f1
    self.f2 = f2

  def write(self, proto):
    proto.f1 = self.f1
    proto.f2 = self.f2

  def read(self, proto):
    self.f1 = proto.f1
    self.f2 = proto.f2
