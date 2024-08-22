//
// Created by chanma on 2024/08/22.
//
#include <iostream>
#include "longest_way.hpp"

//// 実行速度の目安
// node: 4, edge: 5
// real    0m0.043s
// user    0m0.003s
// sys     0m0.021s
// node: 20, edge: 80
// real    0m5.588s
// user    0m5.514s
// sys     0m0.013s
// node: 80, edge: 160
// real    0m35.912s
// user    0m35.747s
// sys     0m0.049s


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
