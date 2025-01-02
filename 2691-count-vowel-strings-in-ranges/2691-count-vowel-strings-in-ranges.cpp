class Solution {
public:
    bool isVowel(char c){
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& qs) {
        vector<int> v(words.size(), 0);
        for(int i = 0; i < words.size(); i++){
            if(isVowel(words[i][0]) and isVowel(words[i][words[i].length()-1]))
                v[i]++;
            if(i != 0)
                v[i] += v[i-1];
        }
        vector<int> res(qs.size());
        for(int i = 0; i < qs.size(); i++)
            res[i] = v[qs[i][1]] - ((qs[i][0]) ? v[qs[i][0]-1] : 0);
        return res;
    }
};