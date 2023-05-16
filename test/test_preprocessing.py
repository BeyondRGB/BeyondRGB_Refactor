""" test_preprocessing.py
Test the preprocessing module

Authors:
    Brendan Grau <https://github.com/Victoriam7>

License:
    © 2022 BeyondRGB
    This code is licensed under the MIT license (see LICENSE.txt for details)
"""

import unittest
import sys
import os

from .context import calibration
from calibration.preprocessing import *


class TestPreprocessing(unittest.TestCase):

    def test_sanity(self):
        preprocess(None)
        self.assertEqual(True, True)

if __name__ == '__main__':
    unittest.main()
