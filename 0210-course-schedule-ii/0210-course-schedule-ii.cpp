class Solution {
public:
    void dfs(vector<int> adj[], vector<bool>& visited, int start,
             stack<int>& topo) {
        visited[start] = true;
        for (int n : adj[start])
            if (!visited[n])
                dfs(adj, visited, n, topo);
        topo.push(start);
    }
    bool isCycle(vector<int> adj[], vector<bool>& visited, int st,
             vector<bool>& recStack) {
        visited[st] = true;
        recStack[st] = true;
        for (int n : adj[st]) {
            if (!visited[n]) {
                if (isCycle(adj, visited, n, recStack))
                    return true;
            } else if (recStack[n]) {
                return true;
            }
        }
        recStack[st] = false;
        return false;
    }
    vector<int> findOrder(int c, vector<vector<int>>& p) {
        vector<int> adj[c];
        for (auto e : p) {
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(c, false);
        vector<bool> recStack(c, false);
        for(int i = 0; i < c; i++){
            if(!visited[i]){
                if(isCycle(adj, visited, i, recStack)) return {};
            }
        }

        for(int i = 0; i < c; i++)
            visited[i] = false;
        
        stack<int> topo;
        vector<int> order;
        for (int i = 0; i < c; i++) {
            if (!visited[i]) {
                dfs(adj, visited, i, topo);
            }
        }
        while (!topo.empty()) {
                order.push_back(topo.top());
                topo.pop();
            }
        return order;
    }
};