class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> out(n+1,false);
        vector<bool> in(n+1,false);
        for(auto t : trust)
            out[t[0]] = true;
        
        int ptj = -1;
        for(int i = 1; i < n+1; i++){
            if(!out[i]) {
                ptj = i; break;
            }
        }
        if (ptj == -1) return -1;

        int count = 0;
        for(auto t : trust){
            if(t[1] == ptj){
                count += 1;
            }
        }
        return (count == n-1) ? ptj : -1;
    }
};