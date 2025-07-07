class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";
        unordered_map<int, int> fre;
        for (char c : t)
            fre[c]++;

        int l = 0, r = 0, cnt = 0, n = s.length(), sI = -1, len = INT_MAX;
        while (r < n) {
            if (fre.find(s[r]) != fre.end()) {
                fre[s[r]]--;
                if (fre[s[r]] >= 0)
                    cnt++;
            }

            if (cnt == t.length()) {
                while (cnt == t.length()) {
                    if(len > (r - l + 1))
                        sI = l, len = r - l + 1;
                    if (fre.find(s[l]) != fre.end()) {
                        fre[s[l]]++;
                        if (fre[s[l]] >= 1)
                            cnt--;
                    }
                    l++;
                }
            }
            r++;
        }
        return (sI == -1) ? "" : s.substr(sI, len);
    }
};