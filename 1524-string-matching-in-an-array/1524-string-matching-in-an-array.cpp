class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        set<string> st;
        for(string s : words)
            for(string t : words)
                if(s != t && t.find(s) != string::npos)
                    st.insert(s);
        for(const auto &it : st)
            res.push_back(it);
        return res;
    }
};