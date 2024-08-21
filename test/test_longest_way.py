import pytest
import sys
import os

sys.path.append(os.path.join(os.path.dirname(__file__), '..'))
from src.longest_way import validate_map_format, load_map


def test_longest_path():
    assert load_map('data/sample_input.txt')
    assert not load_map('data/no_file')

    assert validate_map_format("1, 2, 8.54\r\n2, 3, 3.11\r\n3, 1, 2.19\r\n3, 4, 4\r\n4, 1, 1.4\r\n")
