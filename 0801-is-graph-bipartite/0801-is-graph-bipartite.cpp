class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& adj, int start, vector<int> &color, int clr) {
        color[start] = clr;
        for(int n : adj[start]){
            if(color[n] == -1){
                if(!isBipartite(adj, n, color, !clr)) return false;
            } else if(color[n] == color[start]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        vector<int> color(adj.size(), -1);
        for(int i = 0; i < adj.size(); i++){
            if(color[i] == -1){
                if(!isBipartite(adj, i, color, 0)) return false;
            }
        }
        return true;
    }
};