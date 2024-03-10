import networkx as nx 
import random

def generate_random_dag(num_nodes, num_edges): 
    # remove directed = True to generated undirected graph 
    G = nx.gnm_random_graph(num_nodes,num_edges,directed=True) 
    # uncomment below line to generate DAG when directed = True 
    # G = nx.DiGraph([(u, v) for (u, v) in G.edges() if u < v])
    return G 

num_nodes = 100000
num_edges = 250000 

random_dag = generate_random_dag(num_nodes, num_edges) 
all_edges = list(random_dag.edges())
file_path = "input.txt" 
permutation = (list(range(num_nodes)))
random.shuffle(permutation)
with open(file_path, 'w') as file:
    file.write(f"{num_nodes} {len(all_edges)}\n")
    for edge in all_edges:
        file.write(f"{permutation[edge[0]] + 1} {permutation[edge[1]] + 1}\n")

