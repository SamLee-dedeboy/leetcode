class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        jumps = []
        for index, num in enumerate(reversed(nums)):
            # dst
            if index == 0: 
                jumps.append(0)
            else: 
                # special case
                if num == 0: 
                    jumps.append(len(nums) + 1)
                    continue
                # generate possible dsts from index
                dsts_jumps = jumps[max([0, index - num]): index]
                # update min jump from index
                # print(index, num, dsts_jumps)
                jumps.append(min(dsts_jumps) + 1)
        return jumps[len(nums)-1]

test1 = [2, 3, 1, 1, 4]
test2 = [2,3,0,1,4]
print(Solution().jump(test2))







