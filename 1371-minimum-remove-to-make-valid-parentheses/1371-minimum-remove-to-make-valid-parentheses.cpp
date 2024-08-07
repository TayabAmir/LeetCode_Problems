class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++)
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
                if(st.empty()){
                    s.erase(s.begin() + i);
                    i--;
                }
                else
                    st.pop();
        while(!st.empty()){
            s.erase(s.begin() + st.top());
            st.pop();
        }
        return s;
    }
};