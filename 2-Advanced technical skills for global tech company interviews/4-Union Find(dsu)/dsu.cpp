class DSU{
    vector<ll> par , size , Time;
    DSU(int numberOfNodes){
        par.resize(numberOfNodes); size.resize(numberOfNodes , 1);
        Time.resize(numberOfNodes);
        for (int i = 0 ; i < numberOfNodes ; i ++ )par[i]=i;
    }
public:
    int getParent(int node){
        while(node != par[node]) node = par[node];
        return node;
    }

    int isParent(int x, int y ){
        while(x != par[x] && par[x]!=y) x = par[x];
        return  x ;
    }

    void merge (int node1 , int node2 ){
        node1 = getParent(node1);
        node2 = getParent(node2);

        if(node1 == node2 )return;
        if(size[node1]> size[node2])swap(node1, node2);

        size[node2]+= size[node1];
        par[node1] = node2 ;

    }



};
