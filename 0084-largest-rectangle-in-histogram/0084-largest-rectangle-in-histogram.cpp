class Solution {
public:
    vector<int> nextSmaller(vector<int> heights){
        int n = heights.size();
        stack<int> st;
        vector<int> smaller(n,n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                smaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return smaller;
    }
    vector<int> prevSmaller(vector<int> heights){
        int n = heights.size();
        stack<int> st;
        vector<int> smaller(n,-1);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[i] < heights[st.top()]){
                smaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return smaller;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSmaller(heights);
        int maxArea = -1;
        for(int i = 0; i < heights.size(); i++)
            maxArea = max(maxArea,heights[i] * (next[i] - prev[i] - 1));
        return maxArea;
    }
};