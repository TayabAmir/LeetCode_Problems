class Solution {
public:
    int lowestFrequency(string s){
        int arr[26] = {0};
        for(char c : s)
            arr[c-'a']++;
        for(int i : arr)
            if(i != 0)
                return i;
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& words) {
        vector<int> freq;
        for(string s : words)
            freq.push_back(lowestFrequency(s));
        vector<int> res;
        for(string s : q){
            int f = lowestFrequency(s), r = 0;
            for(int i : freq){
                if(f < i){
                    r++;
                }
            }
            res.push_back(r);
        }
        return res;
    }
};