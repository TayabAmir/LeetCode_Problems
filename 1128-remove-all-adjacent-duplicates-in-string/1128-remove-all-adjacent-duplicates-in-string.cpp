class Solution {
public:
    void getString(string &res, stack<char> st){
        if(st.empty()) return;
        char c = st.top();
        st.pop();
        getString(res,st);
        res += c;
    }
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); ++i){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string res = "";
        getString(res,st);
        return res;
    }
};