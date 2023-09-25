# Topological Sorting

Topological sorting is a fundamental algorithm used to linearly order the vertices of a directed acyclic graph (DAG) in such a way that for every directed edge (u, v), vertex u comes before vertex v in the ordering. This concept finds applications in various domains, such as task scheduling, dependency resolution, and more.

## Introduction to Topological Sorting

Topological sorting is the process of arranging the vertices of a directed graph in a linear order such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. This linear order represents a valid sequence of tasks or dependencies, ensuring that no task is dependent on another task occurring later in the sequence.

## Applications of Topological Sorting

Topological sorting finds applications in various scenarios, including:

- Task Scheduling: Scheduling tasks or jobs with dependencies.
- Build Systems: Determining the correct build order for software projects.
- Course Prerequisites: Planning course prerequisites in academic programs.
- Dependency Resolution: Resolving dependencies in software packages.

## Topological Sort Algorithms

There are two algorithms for topological sorting, but both require that the graph has no cycles to work correctly.

### Depth-First Search (DFS)

DFS works as follows:

1. Start at an unvisited node.
2. Mark the node as visited.
3. Recursively visit all unvisited neighbors of the current node.
4. Add the current node to the topological order after visiting all its neighbors.


### Kahn's Algorithm

Kahn's Algorithm follows these steps:

1. Calculate in-degrees for all nodes in the graph.
2. Initialize a queue with nodes having an in-degree of 0.
3. Dequeue a node, add it to the topological order, and reduce the in-degrees of its neighbors.
4. Enqueue nodes with in-degrees of 0 after decrementing.

**Resources for Topological Sort Algorithm:**
- [GeeksforGeeks Article](https://www.geeksforgeeks.org/topological-sorting/)
- [William Fiset's YouTube Video](https://www.youtube.com/watch?v=eL-KzMXSXXI&ab_channel=WilliamFiset)
