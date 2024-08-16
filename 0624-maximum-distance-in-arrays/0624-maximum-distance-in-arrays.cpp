class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = INT_MAX, largest = INT_MIN,secondLargest = INT_MIN, secondSmallest = INT_MAX,rowLargest = -1, rowSmallest = -1;

        for (int i = 0; i < arrays.size();i++) {
            vector<int> v = arrays[i];
            if (v[0] < smallest) secondSmallest = smallest, smallest = v[0], rowSmallest = i;
            else if (v[0] < secondSmallest)  secondSmallest = v[0];
            if (v.back() > largest) secondLargest = largest, largest = v.back(), rowLargest = i;
            else if (v.back() > secondLargest) secondLargest = v.back();
        }
        if (rowLargest != rowSmallest) 
            return abs(largest - smallest);
        return max(abs(secondLargest - smallest), abs(largest - secondSmallest));
    }
};
