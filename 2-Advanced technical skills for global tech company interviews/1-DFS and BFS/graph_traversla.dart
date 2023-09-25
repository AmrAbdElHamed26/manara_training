import 'dart:collection';

class GraphTraversal {
  void dfs(int node, List<List<int>> graph, List<bool> visited) {
    visited[node] = true;
    print('$node ');

    for (var child in graph[node]) {
      if (!visited[child]) {
        dfs(child, graph, visited);
      }
    }
  }

  void DFS(List<List<int>> graph, int numberOfNodes, int startNode) {
    var visited = List<bool>.filled(numberOfNodes + 1, false);
    dfs(startNode, graph, visited);
    print('');
  }

  void BFS(List<List<int>> graph, int numberOfNodes, int startNode) {
    var q = Queue<int>();
    var visited = List<bool>.filled(numberOfNodes + 1, false);
    visited[startNode] = true;
    q.add(startNode);

    while (q.isNotEmpty) {
      var node = q.removeFirst();
      print('$node ');

      for (var child in graph[node]) {
        if (!visited[child]) {
          visited[child] = true;
          q.add(child);
        }
      }
    }

    print('');
  }
}

void main() {
  var graph = [
    [1],  // Node 0 is not used
    [2, 3], // Node 1 is connected to 2 and 3
    [1, 4, 5], // Node 2 is connected to 1, 4, and 5
    [1, 6, 7], // Node 3 is connected to 1, 6, and 7
    [2], // Node 4 is connected to 2
    [2], // Node 5 is connected to 2
    [3], // Node 6 is connected to 3
    [3], // Node 7 is connected to 3
  ];

  var graphTraversal = GraphTraversal();
  graphTraversal.DFS(graph, 7, 1);
  graphTraversal.BFS(graph, 7, 1);
}
