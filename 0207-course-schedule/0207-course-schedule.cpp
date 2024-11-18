class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int st,
             vector<int>& recStack) {
        visited[st] = true;
        recStack[st] = true;
        for (int n : adj[st]) {
            if (!visited[n]) {
                if (dfs(adj, visited, n, recStack))
                    return true;
            } else if (recStack[n]) {
                return true;
            }
        }
        recStack[st] = false;
        return false;
    }
    bool canFinish(int c, vector<vector<int>>& v) {
        vector<vector<int>> adj(c);
        vector<bool> visited(c, 0);
        for (int i = 0; i < v.size(); i++) {
            int u = v[i][0], w = v[i][1];
            adj[u].push_back(w);
        }
        vector<int> ans(c, false);
        for (int i = 0; i < c; i++) {
            if (!visited[i]) {
                if (dfs(adj, visited, i, ans)) {
                    return false;
                }
            }
        }
        return true;
    }
};