class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m;
        
        stringstream ss(s1);
        string str;
        while(getline(ss, str, ' ')) m[str]++;

        ss.clear(), ss.str(""), ss << s2;  

        while(getline(ss, str, ' ')) m[str]++;

        vector<string> ans;
        for(auto pair : m)
            if(pair.second == 1)
                ans.push_back(pair.first);
        return ans;
    }
};