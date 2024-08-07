class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size(); ++i){
            if(asteroids[i] > 0){
                st.push(i);
            } else {
                while(!st.empty()){
                    if(abs(asteroids[i]) > asteroids[st.top()]){
                        asteroids[st.top()] = 1001;
                        st.pop();
                    } else if(abs(asteroids[i]) < asteroids[st.top()]){
                        asteroids[i] = 1001;
                        break;
                    } else {
                        asteroids[i] = 1001;
                        asteroids[st.top()] = 1001;
                        st.pop();
                        break;
                    }
                }
            }
        }
        vector<int> res;
        for(int i : asteroids)
            if(i != 1001)
                res.push_back(i);
        return res;
    }
};