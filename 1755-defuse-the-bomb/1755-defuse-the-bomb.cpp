class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res;
        if (k < 0) {
            k = abs(k);
            for (int i = 0; i < code.size(); i++) {
                int x = k, sum = 0, j = i-1;
                while (x--) {
                    if (j < 0) j = code.size() - 1;
                    sum += code[j];
                    j--;
                }
                res.push_back(sum);
            }
        } else {
            for (int i = 0; i < code.size(); i++) {
                int x = k, sum = 0, j = (i + 1) % code.size();
                while (x--) {
                    sum += code[j];
                    j = (j + 1) % code.size();
                }
                res.push_back(sum);
            }
        }
        return res;
    }
};