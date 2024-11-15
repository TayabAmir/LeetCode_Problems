class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> out(n+1,0);
        vector<int> in(n+1,0);
        for(auto t : trust)
            out[t[0]] += 1, in[t[1]] += 1;
        
        for(int i = 1; i < n+1; i++)
            if(!out[i] && in[i] == n-1) return i;
        return -1;
    }
};