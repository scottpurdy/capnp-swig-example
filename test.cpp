
#include <assert.h>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include "inner.h"
#include "outer.h"

void testOuter() {
  const char* s = "blah";

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
  assert((a.getFA() - 3.14159) < 0.000001);
  assert((b.getFA() - 3.14159) < 0.000001);
  auto innera = a.getInner();
  auto innerb = b.getInner();
  assert(innera.getF1() == 11);
  assert(innerb.getF1() == 11);
  assert(!strcmp(innera.getF2(), s));
  assert(!strcmp(innerb.getF2(), s));
}

void testInner() {
  const char* s = "blah";

  example::Inner a(11, s);

  ofstream out("test.bin");
  a.write(out);
  out.close();

  example::Inner b;
  ifstream in("test.bin");
  b.read(in);
  in.close();

  unlink("test.bin");

  // assertions
  assert(a.getF1() == 11);
  assert(b.getF1() == 11);
  assert(!strcmp(a.getF2(), s));
  assert(!strcmp(b.getF2(), s));
}

int main(int argc, const char* argv[]) {
  testOuter();
  testInner();
}
