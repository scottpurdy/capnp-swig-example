#!/usr/bin/env python

import os
import unittest

from example.outer import Outer


class MyTest(unittest.TestCase):

  def testSerialization(self):
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
      self.assertAlmostEqual(a.fieldA, 3.14159, places=5)
      self.assertAlmostEqual(b.fieldA, 3.14159, places=5)
      innerA = a.inner
      innerB = b.inner
      self.assertEqual(innerA.f1, 17)
      self.assertEqual(innerB.f1, 17)
      self.assertEqual(innerA.f2, "testtext")
      self.assertEqual(innerB.f2, "testtext")

    finally:
      os.remove("test.bin")


if __name__ == "__main__":
  unittest.main()
