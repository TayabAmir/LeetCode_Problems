class DSU{
private:
    vector<int> parent; 
    vector<int> rank;
public:
    DSU(int V){
        rank.resize(V, 0);
        parent.resize(V);
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(node != parent[node]){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    void unionByRank(int u, int v){
        int p1 = find(u);
        int p2 = find(v);

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        } else if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        } else {
            parent[p2] = p1;
            rank[p1]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(const auto &e : edges){
            if(dsu.find(e[0]-1) == dsu.find(e[1]-1)){
                return e;
            }
            dsu.unionByRank(e[0]-1, e[1]-1);
        }
        return {};
    }
};