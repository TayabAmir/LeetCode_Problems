class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        int penCount = 0;
        while(penCount <= total / cost1){
            int pencils = (total - cost1 * penCount) / cost2;
            ways += (pencils + 1), penCount++;
        }
        return ways;
    }
};