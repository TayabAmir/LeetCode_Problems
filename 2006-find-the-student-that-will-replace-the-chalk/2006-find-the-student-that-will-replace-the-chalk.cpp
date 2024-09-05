class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int s : chalk) sum += s;
        while(k >= sum) k -= sum;
        for(int i = 0; i < chalk.size(); ++i){
            k -= chalk[i];
            if(k < 0) return i;
        }
        return -1;
    }
};