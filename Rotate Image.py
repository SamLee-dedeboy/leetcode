class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n%2 == 1:
            max_i = int((n-1)/2)
        else:
            max_i = int(n/2)
        for i in range(0, max_i):
            for j in range(i, n-i-1):
                # init src as top-left corner
                src = matrix[i][j]
                # rotate in a cycle
                for k in range(0, 4):
                    dst_i, dst_j = self.get_dst(i, j, k, n)
                    # move src to dst
                    tmp = matrix[dst_i][dst_j]
                    matrix[dst_i][dst_j] = src
                    # prepare original dst as new src for next iteration
                    src = tmp
        return matrix

    def get_dst(self, i, j, k, n):
        if k == 0: return j, n - 1 - i
        if k == 1: return n - 1 - i, n - 1 - j
        if k == 2: return n - 1 - j, i
        if k == 3: return i, j

test1 = [[1,2,3],[4,5,6],[7,8,9]]
test2 = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
print(Solution().rotate(test2))
            
