""" tui.py
Runner for tui mode

Functions:
    tui(args) : run the tui

Authors:
    Brendan Grau <https://github.com/Victoriam7>

License:
    © 2022 BeyondRGB
    This code is licensed under the MIT license (see LICENSE.txt for details)
"""
# Python imports
import curses
import textwrap

# Local Imports
from tui.file_sorter import file_sorter
from tui.welcome import welcome
from tui.file_selector import file_selector
from tui.outpath_selector import outpath_selector


def tui(args: list):
    """ Run tui
    [in] args : argument list
    """
    rc = 0
    files = ['target1', 'target2', 'white1', 'white2', 'dark1', 'dark2', 'art1',
             'art2', 'art3', 'art4', 'art5', 'art6', 'art7', 'art8', 'art9',
             'art10', 'art11', 'art12', 'art13', 'art14', 'art15', 'art16']

    stdscr = __init_curses()
    try:
        rc = welcome(stdscr)
        __handle_rc(rc, stdscr)
        rc, files = file_selector(stdscr)
        __handle_rc(rc, stdscr)
        rc, outpath = outpath_selector(stdscr)
        __handle_rc(rc, stdscr)
        rc = file_sorter(stdscr, files)
        __handle_rc(rc, stdscr)
    except Exception:
        rc += 1
    finally:
        __cleanup_curses(stdscr)

    if rc:
        print("TUI Error")


def __handle_rc(rc: int, stdscr):
    """ Handle return codes
    [in] rc     : return code
    [in] stdscr : screen in case we are cleaning up
    """
    if rc == 0:
        return
    elif rc == 1:
        __cleanup_curses(stdscr)
        exit(0)


def __init_curses():
    """ Initialize curses and set options
    [out] curses screen
    """
    # Create screen
    stdscr = curses.initscr()

    # Options
    curses.noecho()  # Don't echo keystrokes
    curses.cbreak()  # Handle keystrokes immediately
    stdscr.keypad(True)  # Enable special character handling
    stdscr.border()
    curses.curs_set(0)

    # Color pairs
    curses.start_color()
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_WHITE)

    return stdscr


def __cleanup_curses(stdscr):
    """ Cleanup curses
    [in] stdscr : screen to clean up
    [post] curses objects cleaned up
    """
    curses.nocbreak()
    stdscr.keypad(False)
    curses.echo()
    curses.endwin()
