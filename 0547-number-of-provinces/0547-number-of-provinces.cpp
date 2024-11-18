class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int start){
        visited[start] = true;
        for(int n : adj[start])
            if(!visited[n])
                dfs(adj,visited,n);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] && i != j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(V,0);
        int prov = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                prov++;
                dfs(adj, visited, i);
            }
        }
        return prov;
    }
};