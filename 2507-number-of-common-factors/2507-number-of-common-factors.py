class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        factors = 1
        n = math.gcd(a,b)
        for i in range(2,n+1):
            if a % i == 0 and b % i == 0:
                factors += 1
        return factors