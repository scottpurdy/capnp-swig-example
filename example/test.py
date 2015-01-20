#!/usr/bin/env python

import os

from example.outer import Outer

if __name__ == "__main__":
  # Write out populated object
  a = Outer(3.14159, 17, "testtext")
  with open("test.bin", "w") as f:
    a.writeToFile(f)

  try:
    # Read in from file
    b = Outer()
    with open("test.bin") as f:
      b.readFromFile(f)

    # Check that the values match
    assert (a.fieldA - 3.14159) < 0.000001
    assert (b.fieldA - 3.14159) < 0.000001
    innerA = a.inner
    innerB = b.inner
    assert(innerA.f1 == 17)
    assert(innerB.f1 == 17)
    assert(innerA.f2 == "testtext")
    assert(innerB.f2 == "testtext")

  finally:
    os.remove("test.bin")
