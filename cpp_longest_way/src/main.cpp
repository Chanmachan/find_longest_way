//
// Created by chanma on 2024/08/22.
//
#include <iostream>
#include "longest_way.hpp"

//// 実行速度の目安
// 5行
// real    0m0.043s
// user    0m0.003s
// sys     0m0.021s
// 150行
// real    0m3.172s
// user    0m3.147s
// sys     0m0.008s
// 178行
// real    15m15.551s
// user    15m15.446s
// sys     0m0.037s


int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Error: one input file needed\n";
		return 1;
	}

	try {
		std::string filename = argv[1];
		auto validated_data = load_map(filename);
		Graph graph = create_graph(validated_data);
#ifdef DEBUG
		write_graph_to_dot(graph, "output.dot");
#endif
		auto longest_path_result = find_longest_path_in_graph(graph);
		auto& longest_path = longest_path_result.first;
		double max_distance = longest_path_result.second;
# ifdef DEBUG
		std::cout << "Longest path length: " << max_distance << std::endl;
		std::cout << std::endl;
#endif
		for (Vertex v : longest_path) {
			std::cout << v << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}

	return 0;
}
