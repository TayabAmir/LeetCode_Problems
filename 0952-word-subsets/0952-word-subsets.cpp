class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);
        for(string s : words2){
            vector<int> freq2(26, 0);
            for(char c : s)
                freq2[c-'a']++;
            for(int i = 0; i < 26; i++)
                freq[i] = max(freq[i], freq2[i]);
        }

        vector<string> res;
        for(string s : words1){
            vector<int> freq2(26, 0);
            for(char c : s) freq2[c-'a']++;
            
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(freq2[i] < freq[i]){
                    flag = false; break;
                }
            }
            if(flag) res.push_back(s);
        }
        return res;
    }
};