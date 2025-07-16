class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        

        def foo(a):
            out = 0
            j = 0
            for v in nums:
                if v&1 == a[j]:
                    out += 1
                    j = 1 - j
            return max(2, out)
        
        print(foo([1,0]))
        return max(foo([0,1]), foo([1,0]), foo([0,0]), foo([1,1]) )
