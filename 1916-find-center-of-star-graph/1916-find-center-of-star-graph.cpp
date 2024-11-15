class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> s;
        for(auto e : edges){
            if(s.find(e[0]) != s.end()) return e[0];
            if(s.find(e[1]) != s.end()) return e[1];
            s.insert(e[0]);
            s.insert(e[1]);
        }
        return -1;
    }
};