class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> x;
        x.push_back(pref[0]);
        for(int i = 1; i < pref.size(); i++)
            x.push_back(pref[i-1] ^ pref[i]);
        return x;
    }
};