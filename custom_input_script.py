import random


def generate_graph_data(num_nodes, num_edges, max_weight=10.0):
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


# Parameters: number of nodes, number of edges, maximum weight of edges
generate_graph_data(80, 160, 10.0)
