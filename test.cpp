
#include <fstream>
#include <string>
#include <unistd.h>
#include <nupic/utils/Log.hpp>
#include "inner.h"
#include "outer.h"

int main(int argc, const char* argv[]) {
  string s("blah");

  example::Outer a(3.14159, 11, s);

  ofstream out("test.bin");
  a.write(out);
  out.close();

  example::Outer b;
  ifstream in("test.bin");
  b.read(in);
  in.close();

  unlink("test.bin");

  // assertions
  NTA_ASSERT((a.getFA() - 3.14159) < 0.0000001);
  NTA_ASSERT((b.getFA() - 3.14159) < 0.0000001);
  auto innera = a.getInner();
  auto innerb = b.getInner();
  NTA_ASSERT(innera.getF1() == 11);
  NTA_ASSERT(innerb.getF1() == 11);
  NTA_ASSERT(innera.getF2() == s);
  NTA_ASSERT(innerb.getF2() == s);
}
