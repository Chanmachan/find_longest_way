import networkx as nx
import matplotlib.pyplot as plt
import sys
import signal


def signal_handler(sig, frame):
    print('Ctrl+C pressed')
    sys.exit(127)


def create_graph(validated_data):
    graph = nx.DiGraph()
    for start, end, distance in validated_data:
        graph.add_edge(start, end, weight=distance)
    return graph


# 双方向の場合、距離が描画されるのは片方のみ
def draw_graph(graph):
    pos = nx.spring_layout(graph)
    edge_labels = nx.get_edge_attributes(graph, 'weight')
    nx.draw(graph, pos, with_labels=True, node_color='skyblue', node_size=2000, edge_color='k', linewidths=1,
            font_size=15)
    nx.draw_networkx_edge_labels(graph, pos, edge_labels={e: f"{w:.2f}" for e, w in edge_labels.items()})
    plt.show()


def find_longest_path_in_graph(graph):
    # 深さ優先探索
    def dfs(node, visited, path_length, path):
        visited.add(node)
        max_length = path_length
        max_path = path + [node]
        for neighbor, data in graph[node].items():
            if neighbor not in visited:
                current_length, current_path = dfs(neighbor, visited, path_length + data['weight'], path + [node])
                # 最長片道切符の旅なので距離が同じなものがあった場合、一応経由ポイントが長い方を保持
                if current_length > max_length or (current_length == max_length and len(current_path) > len(max_path)):
                    max_length = current_length
                    max_path = current_path
        visited.remove(node)
        return max_length, max_path

    longest_path = []
    max_distance = float('-inf')
    for node in graph.nodes():
        distance, path = dfs(node, set(), 0, [])
        if distance > max_distance or (distance == max_distance and len(path) > len(longest_path)):
            max_distance = distance
            longest_path = path
    return longest_path, max_distance


# 数値は9999999を最大値に設定
def validate_map_format(input_map):
    validated_data = []
    added_edges = set()
    for line in input_map.splitlines():
        token = line.split(',')
        if len(token) != 3:
            print('Invalid map format: too many inputs in one line')
            return None
        start, end, distance = token[0].strip(), token[1].strip(), token[2].strip()
        if not (start.isdecimal() and end.isdecimal()):
            print('Invalid map format: ID must be integers')
            return None
        if 7 < len(start) or 7 < len(end):
            print('Invalid map format: ID is too large')
            return None
        try:
            dist = float(distance)
            if distance.isdecimal() and 7 < len(distance):
                print('Invalid map format: distance is too large')
                return None
            if not distance.isdecimal() and (7 < len(distance.split('.')[0]) or 2 < len(distance.split('.')[1])):
                print('Invalid map format: part of distance is too large')
                return None
        except ValueError:
            print(f'Invalid map format: {distance} is not a float')
            return None
        edge = (int(start), int(end))
        if edge not in added_edges:
            validated_data.append((int(start), int(end), dist))
            added_edges.add(edge)
        else:
            print('Invalid map format: same IDs exist')
            return None
    return validated_data


def load_map(filename):
    try:
        with open(filename, 'r') as f:
            lines = f.read()
        validated_data = validate_map_format(lines)
        if validated_data is None:
            return None
        return validated_data
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return None
    except Exception as e:
        print(f"An error occurred: {str(e)}")
        return None


## 実行速度の目安
# node: 4, edge: 5
# real: 0m0.545s
# user: 0m0.290s
# sys: 0m0.070s
# node: 20, edge: 80
# real: 0m8.497s
# user: 0m8.240s
# sys: 0m0.090s
# node: 80, edge: 160
# real: 0m55.058s
# user: 0m54.410s
# sys: 0m0.330s


def main():
    debug_mode = False
    if '--debug' in sys.argv:
        debug_mode = True
        signal.signal(signal.SIGINT, signal_handler)
        sys.argv.remove('--debug')

    if len(sys.argv) != 2:
        print('Error: one input file needed')
        return
    filename = sys.argv[1]
    validated_data = load_map(filename)
    if validated_data is None:
        return
    graph = create_graph(validated_data)
    longest_path, max_distance = find_longest_path_in_graph(graph)

    for node in longest_path:
        print(node)

    if debug_mode:
        print("Maximum Distance:", max_distance)
        draw_graph(graph)


if __name__ == "__main__":
    main()
