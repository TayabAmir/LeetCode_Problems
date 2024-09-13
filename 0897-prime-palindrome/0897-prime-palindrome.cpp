class Solution {
public:
    bool isPrime(int n){
        if(n == 2) return true;
        if(n == 1 || n % 2 == 0) return false;
        for(int i = 3; i*i <= n; i+=2)
            if(n % i == 0) return false;
        return true;
    }
    bool isPalindrome(int n){
        string s = to_string(n);
        int i = 0, j = s.length()-1;
        while(i < j)
            if(s[i++] != s[j--]) return false;
        return true;
    }
    int primePalindrome(int n) {
        if(n <= 2) return 2;
        if(n >= 9989900) return 100030001;
        if(n % 2 == 0) n++;
        while(true){
            if(isPrime(n) && isPalindrome(n)) return n;
            n += 2;
        }
        return -1;
    }
};