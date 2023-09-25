#include <bits/stdc++.h>
using namespace std;

class GraphTraversal{

private:
    void dfs(int node  , vector<vector<int>>&graph , vector<int>&visited){
        visited[node] = true ;
        cout << node << " ";
        for (auto child : graph[node]){
            if(visited[child] == false)dfs(child , graph , visited);
        }
    }

public:
    void DFS(vector<vector<int>>&graph , int numberOfNodes , int startNode ){
        vector<int>visited(numberOfNodes+1, false );
        dfs(startNode, graph , visited);
        cout << endl;
    }

    void BFS(vector<vector<int>>&graph , int numberOfNodes , int startNode ){
        queue<int>q;
        vector<int>visited(numberOfNodes+1 , false ); visited[startNode] = true ;
        q.push(startNode);

        while(!q.empty()){
            int node = q.front();
            cout << node <<  " ";
            for (auto child : graph[node]){
                if(visited[child] == false ){
                    visited[child] = true ;
                    q.push(child);
                }
            }
        }

        cout <<endl;
    }
};
