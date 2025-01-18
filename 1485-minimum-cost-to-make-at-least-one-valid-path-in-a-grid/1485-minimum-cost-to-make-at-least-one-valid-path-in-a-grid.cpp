struct CustomComparator {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) const {
        if (a.first != b.first) {
            return a.first > b.first; 
        }
        if (a.second.first != b.second.first) {
            return a.second.first < b.second.first;
        }
        return a.second.second < b.second.second;
    }
};

class Solution {    
public:
    int is(int r, int c) {
        if (r == -1 && c == 0)
            return 4;
        if (r == 1 && c == 0)
            return 3;
        if (r == 0 && c == -1)
            return 2;
        return 1;
    }
    int minCost(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CustomComparator> pq;
        set<pair<int, int>> visited;
        pq.push({0, {0, 0}});
        int arr[] = {0, -1, 0, 1, 0}, cost = 0, r, c, nr, nc, m = grid.size(),
            n = grid[0].size();
        while (!pq.empty()) {
            r = pq.top().second.first, c = pq.top().second.second;
            cost = pq.top().first;
            pq.pop();
            if (r == m - 1 && c == n - 1)
                return cost;
            
            if(visited.find({r, c}) != visited.end()) continue;
            visited.insert({r, c});

            for (int i = 0; i < 4; i++) {
                nr = r + arr[i], nc = c + arr[i + 1];

                if (0 <= nr && nr < m && 0 <= nc && nc < n) {
                    if (grid[r][c] == is(nr - r, nc - c)) {
                        pq.push({cost+0, {nr, nc}});
                    } else {
                        pq.push({cost+1, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};