
#include <assert.h>
#include <fstream>
#include <string>
#include <unistd.h>
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
  assert((a.getFA() - 3.14159) < 0.0000001);
  assert((b.getFA() - 3.14159) < 0.0000001);
  auto innera = a.getInner();
  auto innerb = b.getInner();
  assert(innera.getF1() == 11);
  assert(innerb.getF1() == 11);
  assert(innera.getF2() == s);
  assert(innerb.getF2() == s);
}
