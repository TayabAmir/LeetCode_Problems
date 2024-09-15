class Solution {
public:
    bool helper(stack<char> st, string part) {
        for(int j = 1; j < part.size(); j++){
            if(st.empty()) return false;
            if(st.top() != part[part.size()-j-1])
                return false;
            st.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == part[part.size()-1] && helper(st,part)) {
                for(int j = 1; j < part.size(); j++) st.pop();
            } else {
                st.push(s[i]);
            }
        }
        s = "";
        while (!st.empty())
            s += st.top(), st.pop();
        reverse(s.begin(),s.end());
        return s;
    }
};