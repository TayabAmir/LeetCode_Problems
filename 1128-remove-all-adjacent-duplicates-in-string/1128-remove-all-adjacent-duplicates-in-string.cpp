class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); ++i)
            (!st.empty() && st.top() == s[i]) ? st.pop() : st.push(s[i]);
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};