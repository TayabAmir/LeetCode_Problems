class Solution {
public:
    int maxArea(vector<int>& h) {
        int maxArea = -1, left = 0, right = h.size()-1;
        while(left <= right)
            maxArea = max(maxArea,min(h[left],h[right]) * (right-left)), h[left] > h[right] ? right-- : left++;
        return maxArea;
    }
};