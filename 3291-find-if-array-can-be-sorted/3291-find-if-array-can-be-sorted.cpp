class Solution {
public:
    bool canSortArray(vector<int>& arr) {
        for(int i = arr.size()- 1; i >= 0; i--)
            for(int j = 0; j < i; j++)
                if(__builtin_popcount(arr[j]) == __builtin_popcount(arr[j+1]) && (arr[j] > arr[j+1]))
                    swap(arr[j], arr[j+1]);
        for(int i = 1; i < arr.size(); i++)
            if(arr[i] < arr[i-1])
                return false;
        return true;
    }
};