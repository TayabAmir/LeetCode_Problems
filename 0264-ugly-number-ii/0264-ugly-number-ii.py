class Solution:
    def nthUglyNumber(self, n: int) -> int:
        h = set([1])
        while len(h) < 10*n:
            h |= {v*2 for v in h} | {v*3 for v in h} | {v*5 for v in h}
        h = sorted(h)

        return h[n-1]