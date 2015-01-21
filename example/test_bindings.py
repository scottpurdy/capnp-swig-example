#!/usr/bin/env python

"""TODO"""

import os
import unittest

from example.bindings import Outer


class TestBindings(unittest.TestCase):

  def testSerialization(self):
    path = "test_bindings.bin"

    a = Outer(3.14159, 17, "test")

    a.write(path)

    try:
      b = Outer()
      b.read(path)

      # Validate
      self.assertAlmostEqual(b.getFA(), 3.14159, places=5)
      inner = b.getInner()
      self.assertEqual(inner.getF1(), 17)
      self.assertEqual(inner.getF2(), "test")
    finally:
      os.remove(path)


if __name__ == "__main__":
  unittest.main()
