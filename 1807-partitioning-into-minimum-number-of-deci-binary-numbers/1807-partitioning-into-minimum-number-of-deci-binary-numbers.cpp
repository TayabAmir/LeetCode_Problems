class Solution {
public:
    int minPartitions(string n) {
        char deci = ' ';
        for(char c : n)
            if(c > deci)
                deci = c;
        return deci-48;
    }
};