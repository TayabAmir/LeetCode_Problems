class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int arr[] = {0, -1, 0, 1, 0};
        int cost = 0;
        int r, c, d, nr, nc;
        while (!pq.empty()) {
            r = pq.top().second.first, c = pq.top().second.second;
            d = pq.top().first;
            pq.pop();

            if (r == n - 1 && c == m - 1)
                return d;

            for (int i = 0; i < 4; i++) {
                nr = r + arr[i], nc = c + arr[i + 1];
                if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                    if (d + grid[nr][nc] < dist[nr][nc]) {
                        dist[nr][nc] = d + grid[nr][nc];
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return cost;
    }
};