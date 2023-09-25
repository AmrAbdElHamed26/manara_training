class DetectCyclesInGraph{

private:
    bool detectCyclesInDirectedGraph(int node , vector<vector<int>>&graph , vector<int>&visited) {
        visited[node] = 1;

        for (int child  : graph[node]) {
            if (visited[child] == 1) {
                return true;
            } else if (visited[child] == 0) {
                if (detectCyclesInDirectedGraph(node, graph, visited)) {
                    return true;
                }
            }
        }

        visited[node] = 2;
        return false;
    }
    bool detectCyclesInUnDirectedGraph(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (auto child : graph[node]) {
            if (visited[child] == true && child != parent) {
                return true;
            } else if (!visited[child]) {
                if (detectCyclesInUnDirectedGraph(child, node, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }



public:
    bool detectCyclesInDirectedGraph(vector<vector<int>>&graph , int numberOfNodes){
        bool sol = true;
        vector<int>visited(numberOfNodes+1 , 0);
        for (int i = 1 ; i <=numberOfNodes ; i ++ ){
            if(visited[i] == 0 )sol|=detectCyclesInDirectedGraph(i , graph , visited);
        }

        return sol;

    }


    bool detectCyclesInUnDirectedGraph(vector<vector<int>>&graph , int numberOfNodes){
        vector<bool>visited(numberOfNodes+1 , false);

        return detectCyclesInUnDirectedGraph(1 ,0 , graph , visited);
    }


};
