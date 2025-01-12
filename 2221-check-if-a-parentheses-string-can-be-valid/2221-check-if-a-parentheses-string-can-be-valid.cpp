class Solution {
public:
    void printStack(stack<int> st){
        while(!st.empty())
            {
                cout << st.top(); st.pop();
            }

    }
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 == 1)
            return false;
        stack<int> st;
        vector<int> ls;
        // int ul = 0;
        for (int i = 0; i < n; ++i) {
            if(locked[i] == '0') ls.push_back(i);
            else if (s[i] == '(')
                st.push(i);
            else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                    continue;
                } 
                if(ls.size() == 0) return false;
                ls.pop_back();
            }
        }
        // printStack(st);
        // cout << endl;
        // for (auto it = ls.begin(); it != ls.end(); ++it)
        //     cout << ' ' << *it;
        if(st.empty()){
            return ls.size() % 2 == 0;
        } else {
            if(ls.size() < st.size() or (ls.size() + st.size()) % 2 == 1 ) return false;

            while(!st.empty()){
                int idx = st.top(); st.pop();
                auto itr = find_if(ls.begin(), ls.end(), [&](int ele) { return ele > idx; });
                if(itr == ls.end()) return false;
                ls.erase(itr);
            }
            return true;
        }
    }
};