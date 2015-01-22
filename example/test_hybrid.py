#!/usr/bin/env python

"""TODO"""

import os
import unittest

from example.hybrid import Hybrid


class TestHybrid(unittest.TestCase):

  def testSerialization(self):
    path = "test_hybrid.bin"

    a = Hybrid(3.14159, 17, "test")

    with open(path, "w") as f:
      a.writeToFile(f)

    try:
      b = Hybrid()
      with open(path) as f:
        b.readFromFile(f)

      # Validate
      self.assertAlmostEqual(b.fieldA, 3.14159, places=5)
      inner = b.inner
      self.assertEqual(inner.getF1(), 17)
      self.assertEqual(inner.getF2(), "test")
    finally:
      os.remove(path)


if __name__ == "__main__":
  unittest.main()
