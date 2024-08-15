class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int _5Count = 0, _10Count = 0;
        for(int i = 0; i < bills.size(); ++i)
            if(bills[i] == 5) ++_5Count;
            else if(bills[i] == 10)
                if(_5Count == 0) return false;
                else  _5Count--,++_10Count;
            else
                if(_10Count == 0 && _5Count >= 3) _5Count -= 3;
                else if(_10Count >= 1 && _5Count >= 1) --_5Count,--_10Count;
                else return false; 
        return true;
    }
};