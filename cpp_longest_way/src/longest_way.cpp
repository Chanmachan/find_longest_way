#include "longest_way.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


void skip_space(std::string& str) {
	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		if (isspace(*it)) {
			str.erase(it);
		}
	}
}

std::vector<edge_t> validate_map_format(const std::string& input_map) {
	std::vector<edge_t> validated_data;
	std::set<std::pair<int, int>> added_edges;
	std::istringstream iss(input_map);
	std::string line;

	while (getline(iss, line)) {
		std::istringstream lineStream(line);
		std::string token;
		std::vector<std::string> tokens;

		while (getline(lineStream, token, ',')) {
			skip_space(token);
			tokens.push_back(token);
		}

		if (tokens.size() != 3) {
			std::cerr << "Invalid map format: too many inputs in one line\n";
			throw std::invalid_argument("Invalid format");
		}

		int start, end;
		double dist;

		if (!std::isdigit(tokens[0][0]) || !std::isdigit(tokens[1][0])) {
			std::cerr << "Invalid map format: ID must be integers\n";
			throw std::invalid_argument("Invalid ID format");
		}

		start = std::stoi(tokens[0]);
		end = std::stoi(tokens[1]);

		if (tokens[0].length() > 7 || tokens[1].length() > 7) {
			std::cerr << "Invalid map format: ID is too large\n";
			throw std::invalid_argument("ID too large");
		}

		// 例外を投げる
		dist = std::stod(tokens[2]);

		if (added_edges.find({start, end}) == added_edges.end()) {
			validated_data.push_back({start, end, dist});
			added_edges.insert({start, end});
		} else {
			std::cerr << "Invalid map format: same IDs exist\n";
			throw std::invalid_argument("Duplicate edge");
		}
	}
	return validated_data;
}

std::vector<edge_t> load_map(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: File '" << filename << "' not found.\n";
		throw std::runtime_error("File not found");
	}

	std::string lines, line;
	while (getline(file, line)) {
		lines += line + "\n";
	}

	return validate_map_format(lines);
}

Graph create_graph(const std::vector<edge_t>& edges) {
	Graph graph;
	for (const auto& edge : edges) {
		add_edge(edge.start, edge.end, boost::property<boost::edge_weight_t, double>(edge.distance), graph);
	}
	return graph;
}

void write_graph_to_dot(const Graph& graph, const std::string& filename) {
	std::ofstream dot_file(filename);
	auto weight_map = get(boost::edge_weight, graph);
	edge_writer<decltype(weight_map)> writer(weight_map);

	boost::write_graphviz(dot_file, graph, boost::default_writer(), writer);
}
