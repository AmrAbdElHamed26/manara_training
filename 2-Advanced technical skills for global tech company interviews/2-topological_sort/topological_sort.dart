import 'dart:collection';

class TopologicalSort {
  void topologicalSortUsingRecursion(
      int node, List<List<int>> graph, List<bool> visited, List<int> sol) {
    visited[node] = true;
    for (var child in graph[node]) {
      if (!visited[child]) topologicalSortUsingRecursion(child, graph, visited, sol);
    }
    sol.add(node);
  }

  List<int> topologicalSortUsingRecursionWrapper(List<List<int>> graph, int numberOfNodes) {
    var sol = <int>[];
    var visited = List<bool>.filled(numberOfNodes, false);
    for (var i = 0; i < numberOfNodes; i++) {
      if (!visited[i]) {
        topologicalSortUsingRecursion(i, graph, visited, sol);
      }
    }
    return sol;
  }

  List<int> topologicalSortUsingQueue(List<List<int>> graph, int numberOfNodes) {
    var sol = <int>[];
    var inDegree = List<int>.filled(numberOfNodes, 0);

    for (var i = 0; i < numberOfNodes; i++) {
      for (var j in graph[i]) {
        inDegree[j]++;
      }
    }

    var q = Queue<int>();
    for (var i = 0; i < numberOfNodes; i++) {
      if (inDegree[i] == 0) {
        q.add(i);
      }
    }

    while (q.isNotEmpty) {
      var node = q.removeFirst();
      sol.add(node);

      for (var child in graph[node]) {
        if (--inDegree[child] == 0) {
          q.add(child);
        }
      }
    }

    return sol;
  }
}
void main() {
  // Example graph represented as an adjacency list
  List<List<int>> graph = [
    [],           // Node 0
    [2, 3],       // Node 1
    [4],          // Node 2
    [4, 5],       // Node 3
    [],           // Node 4
    [6],          // Node 5
    []            // Node 6
  ];

  int numberOfNodes = graph.length;

  // Create an instance of TopologicalSort
  var topologicalSort = TopologicalSort();

  // Perform topological sorting using recursion
  List<int> resultRecursion =
      topologicalSort.topologicalSortUsingRecursionWrapper(graph, numberOfNodes);
  print("Topological Sort using Recursion: $resultRecursion");

  // Perform topological sorting using a queue
  List<int> resultQueue =
      topologicalSort.topologicalSortUsingQueue(graph, numberOfNodes);
  print("Topological Sort using Queue: $resultQueue");
}
