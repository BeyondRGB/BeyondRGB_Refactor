""" test_sanity.py
Tests to check if unittest is working

Authors:
    Brendan Grau <https://github.com/Victoriam7>

License:
    © 2022 BeyondRGB
    This code is licensed under the MIT license (see LICENSE.txt for details)
"""
import unittest

class TestSanity(unittest.TestCase):

    def test_sanity(self):
        self.assertEqual(True, True)

if __name__ == '__main__':
    unittest.main()
