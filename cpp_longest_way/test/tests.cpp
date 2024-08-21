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

BOOST_AUTO_TEST_SUITE_END()

