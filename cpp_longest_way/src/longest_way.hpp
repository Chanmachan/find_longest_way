//
// Created by chanma on 2024/08/22.
//

#ifndef FIND_LONGEST_WAY_LONGEST_WAY_HPP
#define FIND_LONGEST_WAY_LONGEST_WAY_HPP

#include <string>
#include <vector>
#include <set>

struct Edge {
	int start;
	int end;
	double distance;
};

std::vector<Edge> validate_map_format(const std::string& input_map);
std::vector<Edge> load_map(const std::string& filename);

#endif //FIND_LONGEST_WAY_LONGEST_WAY_HPP
