class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        count = 0
        for i in range(0,len(matrix)):
            for j in range(0,len(matrix)):
                if matrix[i][j] < 0:
                    matrix[i][j] = matrix[i][j] * -1
                    count += 1
                    
        res = 0
        for arr in matrix:
            res += sum(arr)

        if count % 2 == 0:
            return res
        else:
            minEle = float('inf')
            for i in range(0,len(matrix)):
                for j in range(0,len(matrix)):
                    if matrix[i][j] < minEle:
                        minEle = matrix[i][j]
            return res - (minEle * 2)
                             
            

