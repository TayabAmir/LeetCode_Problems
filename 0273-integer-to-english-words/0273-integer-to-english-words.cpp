class Solution {
public:
string words(int n)
{
    unordered_map<int, string> m = {{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};
    
    string result;
    int n1 = n / 100, n2 = n / 10 % 10, n3 = n % 10;
    result += (n1 != 0) ? m[n1] + " Hundred" : "";
    if (n1 != 0 && (n2 != 0 || n3 != 0))
        result += " ";
    if (n2 == 1)
    {
        result += m[n2 * 10 + n3];
        return result;
    }
    result += (n2 != 0) ? m[n2 * 10] : "";
    if (n2 != 0 && n3 != 0)
        result += " ";
    result += (n3 != 0) ? m[n3] : "";
    return result;
}
    string numberToWords(int num) {
         unordered_map<int, string> m = {{1,""},{2," Thousand"},{3," Million"},{4," Billion"}};
         int i=1;
         string result = (num==0) ? "Zero" : "";
         while (num > 0)
    {
        string res = words(num % 1000);
        string res1 = (res == "") ? "" : m[i]; 
        string c = (res1 == "" || i == 1 || result == "") ? "" : " ";
        result = res + res1 + c + result;
        i++;
        num /= 1000;
    }
         return result;
    }
}; 