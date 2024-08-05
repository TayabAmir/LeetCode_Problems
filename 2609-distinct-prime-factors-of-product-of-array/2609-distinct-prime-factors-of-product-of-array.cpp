class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        for(int n : nums){
            while (n % 2 == 0) {
                s.insert(2);
                n /= 2;
            }
            for (int i = 3; i <= n; i += 2) {
                while (n % i == 0) {
                    s.insert(i);
                    n /= i;
                }
            }
        }
        return s.size();
    }
};