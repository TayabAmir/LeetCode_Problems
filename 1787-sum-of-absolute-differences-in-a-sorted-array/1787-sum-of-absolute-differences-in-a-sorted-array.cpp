class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> temp = nums;
        int n =  nums.size();
        for(int i = 1;i < n ; i++)
            temp[i] += temp[i-1];
        for(int i : temp)
            cout << i << " ";
        int sum = temp[n-1];
        cout << endl << sum;
        for(int i = 0; i < n; i++)
            if(i>0)
                nums[i] = ((nums[i] * i) - temp[i-1]) + ((sum - temp[i]) - (nums[i] * (n - i -1)));
            else
                nums[i] = ((nums[i] * i)) + ((sum - temp[i]) - (nums[i] * (n - i -1)));
        return nums;
    }
};