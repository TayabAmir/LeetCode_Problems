class Solution {
public:
    static bool comp(int a,int b){
        string s1 = to_string(a), s2 = to_string(b);
        return s1+s2 > s2+s1;
    }
    string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        if(arr[0] == 0) return "0";
        string l = "";
        for (int i = 0; i < arr.size(); i++)
            l += to_string(arr[i]);
        return l;
    }
};