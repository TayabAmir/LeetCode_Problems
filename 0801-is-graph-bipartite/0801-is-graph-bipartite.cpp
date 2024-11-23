class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& adj, int start, vector<int> &color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int neighbor : adj[node]){
                if(color[neighbor] == -1){
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                }
                else if(color[neighbor] == color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        vector<int> color(adj.size(), -1);
        for(int i = 0; i < adj.size(); i++){
            if(color[i] == -1){
                if(!isBipartite(adj, i, color)) return false;
            }
        }
        return true;
    }
};