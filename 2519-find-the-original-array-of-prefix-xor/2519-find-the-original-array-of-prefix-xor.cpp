class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> x(pref.size(),0);
        x[0] = pref[0];
        for(int i = 1; i < pref.size(); i++)
            x[i] = pref[i-1] ^ pref[i];
        return x;
    }
};