class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int num = 0;
        stack<int> st2;
        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ']') {
                string helper = "";
                while (st.top() != '[') {
                    helper = st.top() + helper;
                    st.pop();
                }
                st.pop();
                int n = st2.top();
                st2.pop();
                string temp = "";
                for (int j = 0; j < n; ++j)
                    temp += helper;
                for (char c : temp) 
                    st.push(c);
            } else if (isdigit(s[i])) 
                num = (num * 10) + (s[i] - '0');
              else if (s[i] == '[') {
                st2.push(num);
                st.push(s[i]);
                num = 0;
            } else 
                st.push(s[i]);
        }

        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};