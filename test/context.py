""" context.py
Provide context for importing src modules to test suite

Authors:
    Brendan Grau <https://github.com/Victoriam7>

License:
    © 2022 BeyondRGB
    This code is licensed under the MIT license (see LICENSE.txt for details)
"""
import os
import sys

# Add src directory to module search path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

# Import modules
from src import calibration
from src import utils
from src import tui
