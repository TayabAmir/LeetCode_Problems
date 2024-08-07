class Solution {
public:
    vector<int> rightMax(vector<int> heights){
        int n = heights.size();
        vector<int> right(n);
        right[n-1] = heights[n-1];
        for(int i = n-2; i >= 0; --i)
            right[i] = max(heights[i],right[i+1]);
        return right;
    }
    vector<int> leftMax(vector<int> heights){
        int n = heights.size();
        vector<int> left(n);
        left[0] = heights[0];
        for(int i = 1; i < n; ++i)
            left[i] = max(heights[i],left[i-1]);
        return left;
    }
    int trap(vector<int>& height) {
        vector<int> left = leftMax(height);
        vector<int> right = rightMax(height);
        int water = 0;
        for(int i = 0; i < height.size(); i++)
            water += (min(left[i],right[i]) - height[i]);
        return water;
    }
};