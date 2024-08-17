class Solution(object):
    def countOrders(self, n):
        return (math.factorial(2*n) / 2**n) % 1000000007
        