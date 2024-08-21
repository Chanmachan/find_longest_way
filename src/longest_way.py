import networkx as nx
import matplotlib.pyplot as plt
import sys


def create_graph(validated_data):
    graph = nx.DiGraph()
    for start, end, distance in validated_data:
        graph.add_edge(start, end, weight=distance)
    return graph


def draw_graph(graph):
    pos = nx.spring_layout(graph)
    edge_labels = nx.get_edge_attributes(graph, 'weight')
    nx.draw(graph, pos, with_labels=True, node_color='skyblue', node_size=2000, edge_color='k', linewidths=1, font_size=15)
    nx.draw_networkx_edge_labels(graph, pos, edge_labels={e: f"{w:.2f}" for e, w in edge_labels.items()})
    plt.show()


def validate_map_format(input_map):
    validated_data = []
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
            validated_data.append((int(start), int(end), dist))
        except ValueError:
            print(f'Invalid map format: {distance} is not a float')
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


def main():
    debug_mode = False
    if '--debug' in sys.argv:
        debug_mode = True
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

