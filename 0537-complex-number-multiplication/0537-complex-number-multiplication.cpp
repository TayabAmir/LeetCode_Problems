class Solution {
public:
    int getRealNumber(string s, int &i){
        string realNo = "";
        while(s[i] != '+')
            realNo += s[i],i++;
        return stoi(realNo);
    }
    int getImaginaryNumber(string s, int i){
        string imaginaryNo = "";
        while(s[i] != 'i')
            imaginaryNo += s[i], i++;
        return stoi(imaginaryNo);
    }
    string complexNumberMultiply(string num1, string num2) {
        int idx1 = 0, idx2 = 0, r1 = getRealNumber(num1, idx1), r2 = getRealNumber(num2, idx2), i1 = getImaginaryNumber(num1, idx1+1), i2 =  getImaginaryNumber(num2, idx2+1);
        return to_string(r1*r2-i1*i2) + "+" + to_string(r1*i2+r2*i1) + "i";
    }
};