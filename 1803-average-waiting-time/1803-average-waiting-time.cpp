class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitingTime = 0;
        int orderTime = customers[0][0];
        for(int i = 0; i < customers.size(); i++){
            if(orderTime < customers[i][0]) orderTime = customers[i][0];
            waitingTime += (customers[i][1] + ( orderTime-customers[i][0]));
            orderTime += customers[i][1];
        }
        return waitingTime / customers.size();
    }
};