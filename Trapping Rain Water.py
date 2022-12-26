class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        return self.wrap(height)

    def wrap(self, height, reversed=False):
        total = 0
        i = 1
        seq = [height[0]]
        while i < len(height):
            while i < len(height) and height[i] <= seq[0]:
                seq.append(height[i])
                i += 1
            if i == len(height) and not reversed:
                total += self.wrap(seq[::-1], True)
                continue
            if i < len(height) and height[i] > seq[0]:
                seq.append(height[i])
            total += self.volume(seq)
            if i < len(height):
                seq = [height[i]]
                i += 1
        return total

    def volume(self, seq):
        if len(seq) < 3: return 0
            
        max_height = min([seq[0], seq[-1]])
        total_volume = 0
        for i in seq[1:-1]:
            if max_height > i:
                total_volume += max_height - i
        # print(seq, total_volume)
        return total_volume

solution = Solution()
    #     0  1  2  3  4  5  6  7  8  9  10 11
height_1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] # 6
height_2 = [4,2,0,3,2,5] # 9
height_3 = [2, 0, 2] # 2
height_4 = [4, 2, 3] # 1
height_5 = [4,9,4,5,3,2] # 1
height_6 = [5, 4, 1, 2] # 1
height_7 = [9,6,8,8,5,6,3] # 3
tests = [height_1, height_2, height_3, height_4, height_5, height_6, height_7]
# print(solution.trap(height_3))
for test in tests:
    print(solution.trap(test))