class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n,0);
        for(auto e : edges) inDegrees[e[1]]++;

        int winner, count = 0;
        for(int i = 0; i < n; i++)
            if(!inDegrees[i]) winner = i, count++;
        return (count == 1) ? winner : -1;
    }
};