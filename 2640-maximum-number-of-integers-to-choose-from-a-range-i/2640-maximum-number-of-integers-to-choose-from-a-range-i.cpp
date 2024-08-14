class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> arr(n + 1, false);
        for (int i : banned)
            if (i <= n)
                arr[i] = true;
        int sum = 0, count = 0;
        for (int i = 1; i <= n; ++i) {
            if (!arr[i])
                sum += i;
            if (!arr[i] && sum <= maxSum)
                count++;
        }
        return count;
    }
};