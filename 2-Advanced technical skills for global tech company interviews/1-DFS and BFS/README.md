# Graph Traversal Using DFS and BFS

This Template contains code and explanations for graph traversal using two fundamental graph traversal algorithms: Depth-First Search (DFS) and Breadth-First Search (BFS). Graph traversal is a fundamental concept in computer science and is widely used in various applications such as pathfinding, network analysis, and more.


## Introduction

Graph traversal is the process of visiting all the vertices (nodes) of a graph in a specific order. DFS and BFS are two common algorithms for performing graph traversal:

- **DFS (Depth-First Search):** DFS explores as far as possible along a branch before backtracking. It uses a stack or recursion to keep track of nodes to visit.

https://github.com/AmrAbdElHamed26/manara_training/assets/86882938/2b4ded2a-a659-498d-88d5-e1b0befe27a3


- **BFS (Breadth-First Search):** BFS explores all the neighbors of a node before visiting their child nodes. It uses a queue data structure to maintain the order of nodes to visit.

This repository provides implementations of DFS and BFS for graph traversal, along with explanations and usage instructions.

https://github.com/AmrAbdElHamed26/manara_training/assets/86882938/a35f779f-33ac-4858-87fd-6721dd3d00cf


## DFS (Depth-First Search)

DFS is a recursive algorithm that explores as deeply as possible along each branch before backtracking. It is often used to find paths, cycles, or connected components within a graph.


### How DFS Works

1. Start at the initial node (e.g., the source node).
2. Mark the node as visited.
3. Explore an unvisited neighbor of the current node.
4. Repeat step 3 for the unvisited neighbor until no unvisited neighbors remain.
5. Backtrack to the previous node and repeat steps 3-4 until all nodes are visited.

## BFS (Breadth-First Search)

BFS explores all the neighbors of a node before visiting their child nodes. It is commonly used to find the shortest path in an unweighted graph.

### How BFS Works

1. Start at the initial node (e.g., the source node).
2. Mark the node as visited.
3. Enqueue the node.
4. Dequeue a node from the queue and explore its unvisited neighbors.
5. Enqueue the unvisited neighbors.
6. Repeat steps 4-5 until the queue is empty.


