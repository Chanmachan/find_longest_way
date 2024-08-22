import argparse
import random

def generate_graph_data(num_nodes, num_edges, max_weight):
    edges = set()
    while len(edges) < num_edges:
        start = random.randint(1, num_nodes)
        end = random.randint(1, num_nodes)
        if start != end:
            edges.add((start, end))

    with open('data/custom_input.txt', 'w') as file:
        for start, end in edges:
            weight = round(random.uniform(1.0, max_weight), 2)
            file.write(f"{start}, {end}, {weight}\n")


def main():
    parser = argparse.ArgumentParser(description="Generate graph data for testing.")
    parser.add_argument("num_nodes", type=int, help="Number of nodes in the graph")
    parser.add_argument("num_edges", type=int, help="Number of edges in the graph")
    parser.add_argument("max_weight", type=float, help="Maximum weight for an edge")

    args = parser.parse_args()

    # Call the function with arguments from the command line
    generate_graph_data(args.num_nodes, args.num_edges, args.max_weight)

if __name__ == "__main__":
    main()