class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length();i+=(2*k)){
            int m = i,n = i+k-1;
            if(n>=s.length()) n = s.length()-1;
            while(m<n)
                swap(s[m++],s[n--]);
        }
        return s;
    }
};