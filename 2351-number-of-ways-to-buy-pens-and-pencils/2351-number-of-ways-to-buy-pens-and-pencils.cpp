class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        for(int penCount = 0; penCount <= total / cost1; penCount++)
            ways = ways + (total - cost1 * penCount) / cost2 + 1 ;
        return ways;
    }
};