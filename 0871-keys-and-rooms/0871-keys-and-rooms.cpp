class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int start){
        visited[start] = true;
        for(int adj : rooms[start]){
            if(!visited[adj]){
                dfs(rooms, visited, adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V = rooms.size();
        vector<bool> visited(V, false);
        dfs(rooms, visited, 0);
        for(bool b : visited)
            if(!b) return false;
        return true;
    }
};