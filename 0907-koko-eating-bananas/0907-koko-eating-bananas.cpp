class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int left = 1, right = *max_element(p.begin(), p.end());
        int o = right;
        while (left <= right) {
            long long c = 0;
            long long mid = left + (right - left) / 2;
            for (int i = 0; i < p.size(); i++)
                c += (p[i] + mid - 1) / mid;
            if (c > h)
                left = mid + 1;
            else
                o = mid, right = mid - 1;
        }
        return o;
    }
};