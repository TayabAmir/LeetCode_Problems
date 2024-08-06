class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';

        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                num = (num * 10) + (s[i] - '0');
            } 
            if((!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ') || i == s.length() - 1){
                if(op == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                } else if(op == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if(op == '+'){
                    st.push(num);
                } else if(op == '-'){
                    st.push(-num);
                }
                op = s[i];
                num = 0;
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
