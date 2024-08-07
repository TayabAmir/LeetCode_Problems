class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> wait(temperatures.size(),0);
        stack<int> st;
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()] ){
                wait[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return wait;
    }
};