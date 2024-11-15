class Solution {
public:
    void dfs(vector<int> adj[], vector<bool>& visited, int source){
        visited[source] = true;
        for(int n : adj[source]){
            if(!visited[n]){
                dfs(adj, visited, n);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(adj, visited, source);
        return visited[destination];
    }
};