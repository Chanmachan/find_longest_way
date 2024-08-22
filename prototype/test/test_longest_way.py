import pytest
import sys
import os

sys.path.append(os.path.join(os.path.dirname(__file__), '..'))
from src.longest_way import validate_map_format, load_map, create_graph, find_longest_path_in_graph


def test_case_1():
    data = [
        (1, 2, 8.54),
        (2, 3, 3.11),
        (3, 1, 2.19),
        (3, 4, 4),
        (4, 1, 1.4),
    ]
    graph = create_graph(data)
    longest_path, max_distance = find_longest_path_in_graph(graph)
    assert longest_path == [1, 2, 3, 4], f"Expected path [1, 2, 3, 4], but got {longest_path}"
    assert max_distance == 15.649999999999999, f"Expected distance 15.649999999999999, but got {max_distance}"


# 2
def test_case_2():
    data = [
        (1, 2, 3.0),
        (1, 3, 2.0),
        (2, 4, 2.0),
        (3, 4, 5.0),
        (4, 5, 1.0)
    ]
    graph = create_graph(data)
    longest_path, max_distance = find_longest_path_in_graph(graph)
    assert longest_path == [1, 3, 4, 5], f"Expected path [1, 3, 4, 5], but got {longest_path}"
    assert max_distance == 8.0, f"Expected distance 8.0, but got {max_distance}"


# 3
def test_case_3():
    data = [
        (1, 2, 3.0), (1, 3, 5.0), (2, 4, 2.0), (2, 5, 4.0),
        (3, 5, 3.0), (3, 6, 7.0), (4, 7, 1.0), (5, 7, 3.0), (6, 7, 2.0)
    ]
    graph = create_graph(data)
    longest_path, max_distance = find_longest_path_in_graph(graph)
    assert longest_path == [1, 3, 6, 7], f"Expected path [1, 3, 6, 7], but got {longest_path}"
    assert max_distance == 14.0, f"Expected distance 14.0, but got {max_distance}"


# 4
def test_case_4():
    data = [
        (1, 2, 1.5), (1, 3, 2.5), (2, 4, 2.0), (2, 5, 3.5),
        (3, 4, 4.0), (4, 5, 1.0), (4, 6, 3.0), (5, 6, 2.0)
    ]
    graph = create_graph(data)
    longest_path, max_distance = find_longest_path_in_graph(graph)
    assert longest_path == [1, 3, 4, 5, 6], f"Expected path [1, 3, 4, 5, 6], but got {longest_path}"
    assert max_distance == 9.5, f"Expected distance 9.5, but got {max_distance}"


# 5
def test_case_5():
    data = [
        (1, 2, 2.0), (2, 3, 3.0), (3, 4, 1.5), (4, 2, 0.5), (3, 5, 4.0)
    ]
    graph = create_graph(data)
    longest_path, max_distance = find_longest_path_in_graph(graph)
    assert longest_path == [1, 2, 3, 5], f"Expected path [1, 2, 3, 5], but got {longest_path}"
    assert max_distance == 9.0, f"Expected distance 9.0, but got {max_distance}"


def test_find_longest_path_in_graph():
    test_case_1()
    test_case_2()
    test_case_3()
    test_case_4()
    test_case_5()


def test_validate_map_format():
    assert not validate_map_format("1a, 2, 8.54\r\n2, 3, 3.11\r\n3, 1, 2.19\r\n3, 4, 4\r\n4, 1, 1.4\r\n")
    assert validate_map_format("1, 2, 8.54\r\n2, 3, 3.11\r\n3, 1, 2.19\r\n3, 4, 4\r\n4, 1, 1.4\r\n")


def test_load_map():
    assert not load_map('no_file')


# 関数を呼び出してテストを実行
test_find_longest_path_in_graph()
test_validate_map_format()
test_load_map()
