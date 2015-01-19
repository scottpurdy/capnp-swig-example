@0xf1269555a5eb3503;

struct OuterProto {
  fieldA @0 :Float32;
  inner @1 :InnerProto;
}

struct InnerProto {
  f1 @0 :UInt16;
  f2 @1 :Text;
}
