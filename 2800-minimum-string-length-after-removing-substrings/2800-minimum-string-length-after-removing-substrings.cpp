class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i = s.length()-1; i >= 0; --i)
            (s[i] == 'A' && !st.empty() && st.top() == 'B') ? st.pop() : (s[i] == 'C' && !st.empty() && st.top() == 'D') ? st.pop() :  st.push(s[i]);
        return st.size();
    }
};