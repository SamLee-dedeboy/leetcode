class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        perms = [[nums[0]]]
        for num in nums[1:]:
            new_perm = []
            for perm in perms:
                for slot in range(len(perm)+1):
                    # copy original perm
                    inserted_perm = list(perm)
                    # insert
                    inserted_perm.insert(slot, num)
                    new_perm.append(inserted_perm)
            # update perms
            perms = new_perm
        return perms

test1 = [1, 2, 3]
test2 = [0, 1]
test3 = [1]
print(Solution().permute(test3))

