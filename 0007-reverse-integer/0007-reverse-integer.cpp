class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        (s[0] == '-') ? std::reverse(s.begin()+1,s.end()) : std::reverse(s.begin(),s.end());
        long long n = stoll(s);
        return (n <= INT_MAX &&  n >= INT_MIN) ? stoi(s) : 0; 
    }
};