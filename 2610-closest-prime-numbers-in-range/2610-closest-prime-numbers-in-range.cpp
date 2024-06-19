class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes(2,-1);
        vector<bool> isPrime(right-left+1,true);
        int lim = sqrt(right);
        for(int i=2; i <= lim; i++){
            for(int j = max(i * i, (left + i - 1) / i * i); j <= right; j+=i){
                isPrime[j-left] = false;
            }
        }
        if (left == 1)
            isPrime[0] = false;
        int i=0,count=0,temp;
        while(true){
            if(isPrime[i]){
                primes[count++] = left+i;
            }
            i++;
            if(count ==2 || i+left > right) break;
        }
        if(count <= 1)
            primes[0] = primes[1] = -1;
        while(i+left <= right){
            if(isPrime[i]){
                if(primes[1] - primes[0] > left+i - primes[1]){
                    primes[0] = primes[1];
                    primes[1] = left+i;
                }
                else if(primes[1] - primes[0] > (left+i) - temp){
                    primes[0] = temp;
                    primes[1] = left+i;
                }
                temp = left+i;
            }
            i++;
        }
        return primes;
    }
};