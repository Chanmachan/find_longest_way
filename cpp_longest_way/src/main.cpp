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
		for (const auto& edge : validated_data) {
			std::cout << "Edge from " << edge.start << " to " << edge.end << " with distance " << edge.distance << '\n';
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}

	return 0;
}
