//
// Created by chanma on 2024/08/22.
//
#include <iostream>
#include "longest_way.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Error: one input file needed\n";
		return 1;
	}

	try {
		std::string filename = argv[1];
		auto validated_data = load_map(filename);
		Graph graph = create_graph(validated_data);
//		write_graph_to_dot(graph, "output.dot");
		auto longest_path_result = find_longest_path_in_graph(graph);
		auto& longest_path = longest_path_result.first;
		double max_distance = longest_path_result.second;

		std::cout << "Longest path length: " << max_distance << "\n";
		std::cout << "Path: ";
		for (Vertex v : longest_path) {
			std::cout << v << " ";
		}
		std::cout << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}

	return 0;
}
