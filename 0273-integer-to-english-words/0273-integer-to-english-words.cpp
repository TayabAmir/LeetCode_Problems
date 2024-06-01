class Solution {
public:

string words(int n) {
    unordered_map<int, string> units = {
    {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
    {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"},
    {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
    {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
    {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
};

    if (n == 0) return "";

    string result;
    int n1 = n / 100, n2 = n / 10 % 10, n3 = n % 10;

    if (n1 != 0) 
        result += units[n1] + " Hundred";
    
    if (n2 == 1) {
        if (!result.empty()) result += " ";
        result += units[n2 * 10 + n3];
        return result;
    }
    if (n2 != 0) {
        if (!result.empty()) result += " ";
        result += units[n2 * 10];
    }
    if (n3 != 0) {
        if (!result.empty()) result += " ";
        result += units[n3];
    }
    return result;
}
    string numberToWords(int num) {
        unordered_map<int, string> m = {
    {1, ""}, {2, " Thousand"}, {3, " Million"}, {4, " Billion"}
};
    if (num == 0) return "Zero";
    string result;
    int i = 1;

    while (num > 0) {
        string res = words(num % 1000);
        if (!res.empty()) {
            if (!result.empty()) result = " " + result;
            result = res + m[i] + result;
        }
        num /= 1000;
        i++;
    }
    return result;
}
}; 