class TopologicalSort {
private:
    void topologicalSortUsingRecursion(int node, vector<vector<int>> &graph, vector<bool> visited, vector<int> &sol) {
        visited[node] = true;
        for (auto child: graph[node]) {
            if (visited[child] == false)topologicalSortUsingRecursion(child, graph, visited, sol);
        }
        sol.push_back(node);
    }

public:
    /// nodes from 1 to number of nodes
    vector<int> topologicalSortUsingRecursion(vector<vector<int>> &graph, int numberOfNodes) {
        vector<int> sol;
        vector<bool> visited(numberOfNodes, false);
        for (int i = 1; i <= numberOfNodes; i++) {
            if (!visited[i]) {
                topologicalSortUsingRecursion(i, graph, visited, sol);
            }
        }
        return sol;
    }

    vector<int> topologicalSortUsingQueue(vector<vector<int>> &graph, int numberOfNodes) {
        vector<int> sol;
        vector<int> inDegree(numberOfNodes, 0);

        for (int i = 0; i < numberOfNodes; ++i) {
            for (int j: graph[i]) {
                inDegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numberOfNodes; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            sol.push_back(node);

            for (int child: graph[node]) {
                if (--inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        return sol;
    }
};
