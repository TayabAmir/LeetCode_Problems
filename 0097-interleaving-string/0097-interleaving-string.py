class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        
        if len(s1) + len(s2) != len(s3):  return False
        @lru_cache
        def foo(i,j):
            k = i + j
            if k == len(s3): return True
            out = False
            if i < len(s1) and s1[i] == s3[k]:
                out |= foo(i+1,j)
            if j < len(s2) and s2[j] == s3[k]:
                out |= foo(i,j+1)
            return out
        
        return foo(0,0)
