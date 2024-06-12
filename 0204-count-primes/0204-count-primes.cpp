class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        int count = 0;
        for(int p = 2; p * p < n; p++){
            if(prime[p]){
                for(int j=p*p;j< n;j+=p){
                    prime[j] = false;
                }
            }
        }
        for(int i=2;i<n;i++)
            if(prime[i]) count++;
        return count;
    }
};