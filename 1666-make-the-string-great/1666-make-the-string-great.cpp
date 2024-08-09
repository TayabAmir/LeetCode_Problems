class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); ++i) 
            (!st.empty() && ((s[i] > 95 &&  st.top() == s[i] - 32) || (s[i] < 95 && st.top() == s[i] + 32))) ? st.pop() : st.push(s[i]);
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};