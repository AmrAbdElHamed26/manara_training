class Dijkstra{
private:
    int const INF = 1e9 ;
public:

    vector<long long > dijkstra(int startNode , int numberOfNodes, vector<vector<pair<int,int>>>&graph ){
        vector<long long int >distance(numberOfNodes+1 , INF);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,startNode});
        while(!pq.empty()){
            pair<int,int> current = pq.top() ;
            pq.pop();

            int cost = current.first , node = current.second ;

            if(distance[node]<cost)continue;

            for (auto child : graph[node]){
                ll newCost = distance[node]+child.second ;
                if(newCost < distance[child.first]){
                    distance[child.first] = newCost ;
                    pq.push({newCost , child.first});
                }
            }
        }

        return distance ;
    }
};
