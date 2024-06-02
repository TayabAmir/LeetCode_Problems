class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> arr;
        int sum = 0;
        for (int i = 0; i < operations.size(); i++) {
        if (operations[i] == "C") 
            arr.pop_back();
        else if (operations[i] == "D") 
            arr.push_back(arr.back() * 2);
        else if (operations[i] == "+") 
            arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
        else 
            arr.push_back(stoi(operations[i]));
        
    }
        for(int i=0;i<arr.size();i++)
            sum += arr[i];
        return sum;
    }
};