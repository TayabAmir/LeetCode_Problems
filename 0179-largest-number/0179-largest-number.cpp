class Solution {
public:
    static bool comp(int a,int b){
        string s1 = to_string(a), s2 = to_string(b);
        if(s1[0] > s2[0]) return true;
        if(s1+s2 > s2+s1) return true;
        return false;
    }
    string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        if(arr[0] == 0) return "0";
        string l = "";
        for (int num : arr)
            l += to_string(num);
        return l;
    }
};