//
// Created by chanma on 2024/08/22.
//

#ifndef FIND_LONGEST_WAY_LONGEST_WAY_HPP
#define FIND_LONGEST_WAY_LONGEST_WAY_HPP

#include <string>
#include <vector>
#include <set>
#include <utility>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

// グラフのタイプ定義
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
		boost::no_property, boost::property<boost::edge_weight_t, double>> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;

typedef struct edge_s {
	int start;
	int end;
	double distance;
} edge_t;

// エッジの重みを書き出すために必要になった
// 型の不一致によるエラーを解消
template <typename WeightMap>
class edge_writer {
public:
	edge_writer(WeightMap weight_map) : wm(weight_map) {}

	template <typename Edge>
	void operator()(std::ostream& out, const Edge& e) const {
		out << "[label=\"" << wm[e] << "\"]";
	}

private:
	WeightMap wm;
};

std::vector<edge_t> validate_map_format(const std::string& input_map);
std::vector<edge_t> load_map(const std::string& filename);
Graph create_graph(const std::vector<edge_t>& edges);
void write_graph_to_dot(const Graph& graph, const std::string& filename);

#endif //FIND_LONGEST_WAY_LONGEST_WAY_HPP
