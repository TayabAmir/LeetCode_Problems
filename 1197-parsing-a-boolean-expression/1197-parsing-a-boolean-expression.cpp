class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> st;
        for (char c : e) {
            if (c == ')') {
                string s;
                while (!st.empty() && st.top() != '(') {
                    if (st.top() != '(')
                        s += st.top();
                    st.pop();
                }
                st.pop();
                char c2 = st.top();
                st.pop();

                if (c2 == '!') {
                    if (s[0] == 't')
                        st.push('f');
                    else
                        st.push('t');
                }
                int tCount = 0, fCount = 0;
                for (char b : s) {
                    (b == 't') ? tCount += 1 : fCount += 1;
                }
                if (c2 == '&') {
                    if (fCount == 0)
                        st.push('t');
                    else
                        st.push('f');
                }

                if (c2 == '|') {
                    if (tCount >= 1)
                        st.push('t');
                    else {
                        st.push('f');
                    }
                }
            } 
            else if (c != ',') {
                st.push(c);
            }
        }
        return st.top() == 't' ? true : false;
    }
};