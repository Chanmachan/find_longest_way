//
// Created by chanma on 2024/08/22.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <fstream>
#include "../src/longest_way.hpp"

BOOST_AUTO_TEST_SUITE(my_testsuite)

BOOST_AUTO_TEST_CASE(testValidateMapFormat) {
		// 正常な入力
		std::string valid_input = "1,2,3.5\n2,3,4.5";
		std::vector<edge_t> result = validate_map_format(valid_input);
		BOOST_REQUIRE_EQUAL(result.size(), 2);  // 期待されるエッジの数
		BOOST_CHECK_EQUAL(result[0].start, 1);
		BOOST_CHECK_EQUAL(result[0].end, 2);
		BOOST_CHECK_CLOSE(result[0].distance, 3.5, 0.001);

		// 不正な入力
		std::string invalid_input = "1,2\n2,3,4.5";
		BOOST_CHECK_THROW(validate_map_format(invalid_input), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testLoadMap) {
		// 存在しないファイル
		BOOST_CHECK_THROW(load_map("nonexistentfile.txt"), std::runtime_error);

		// 一時的なテストファイルを作成
		std::string filename = "testfile.txt";
		std::ofstream testfile(filename);
		testfile << "1,2,3.5\n2,3,4.5";
		testfile.close();

		// ファイル読み込みと内容の検証
		std::vector<edge_t> result = load_map(filename);
		BOOST_REQUIRE_EQUAL(result.size(), 2);
		BOOST_CHECK_EQUAL(result[0].start, 1);
		BOOST_CHECK_EQUAL(result[0].end, 2);
		BOOST_CHECK_CLOSE(result[0].distance, 3.5, 0.001);

		// テストファイルを削除
		std::remove(filename.c_str());
}


BOOST_AUTO_TEST_CASE(test_case_1) {
		std::vector<edge_t> data = {
				{1, 2, 8.54}, {2, 3, 3.11}, {3, 1, 2.19}, {3, 4, 4}, {4, 1, 1.4}
		};
		Graph graph = create_graph(data);
		auto result = find_longest_path_in_graph(graph);
		std::vector<Vertex> expected_path = {1, 2, 3, 4};
		BOOST_CHECK_EQUAL_COLLECTIONS(result.first.begin(), result.first.end(), expected_path.begin(), expected_path.end());
		BOOST_CHECK_CLOSE(result.second, 15.65, 0.001);
}

BOOST_AUTO_TEST_CASE(test_case_2) {
		std::vector<edge_t> data = {
				{1, 2, 3.0}, {1, 3, 2.0}, {2, 4, 2.0}, {3, 4, 5.0}, {4, 5, 1.0}
		};
		Graph graph = create_graph(data);
		auto result = find_longest_path_in_graph(graph);
		std::vector<Vertex> expected_path = {1, 3, 4, 5};
		BOOST_CHECK_EQUAL_COLLECTIONS(result.first.begin(), result.first.end(), expected_path.begin(), expected_path.end());
		BOOST_CHECK_CLOSE(result.second, 8.0, 0.001);
}

BOOST_AUTO_TEST_CASE(test_case_3) {
		std::vector<edge_t> data = {
				{1, 2, 3.0}, {1, 3, 5.0}, {2, 4, 2.0}, {2, 5, 4.0},
				{3, 5, 3.0}, {3, 6, 7.0}, {4, 7, 1.0}, {5, 7, 3.0}, {6, 7, 2.0}
		};
		Graph graph = create_graph(data);
		auto result = find_longest_path_in_graph(graph);
		std::vector<Vertex> expected_path = {1, 3, 6, 7};
		BOOST_CHECK_EQUAL_COLLECTIONS(result.first.begin(), result.first.end(), expected_path.begin(), expected_path.end());
		BOOST_CHECK_CLOSE(result.second, 14.0, 0.001);
}

BOOST_AUTO_TEST_CASE(test_case_4) {
		std::vector<edge_t> data = {
				{1, 2, 1.5}, {1, 3, 2.5}, {2, 4, 2.0}, {2, 5, 3.5},
				{3, 4, 4.0}, {4, 5, 1.0}, {4, 6, 3.0}, {5, 6, 2.0}
		};
		Graph graph = create_graph(data);
		auto result = find_longest_path_in_graph(graph);
		std::vector<Vertex> expected_path = {1, 3, 4, 5, 6};
		BOOST_CHECK_EQUAL_COLLECTIONS(result.first.begin(), result.first.end(), expected_path.begin(), expected_path.end());
		BOOST_CHECK_CLOSE(result.second, 9.5, 0.001);
}

BOOST_AUTO_TEST_CASE(test_case_5) {
		std::vector<edge_t> data = {
				{1, 2, 2.0}, {2, 3, 3.0}, {3, 4, 1.5}, {4, 2, 0.5}, {3, 5, 4.0}
		};
		Graph graph = create_graph(data);
		auto result = find_longest_path_in_graph(graph);
		std::vector<Vertex> expected_path = {1, 2, 3, 5};
		BOOST_CHECK_EQUAL_COLLECTIONS(result.first.begin(), result.first.end(), expected_path.begin(), expected_path.end());
		BOOST_CHECK_CLOSE(result.second, 9.0, 0.001);
}

BOOST_AUTO_TEST_SUITE_END()

