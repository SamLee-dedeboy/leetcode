class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        perms = [[nums[0]]]
        needs_check = {}
        needs_check[nums[0]] = True
        for num in nums[1:]:
            if num not in needs_check:
                needs_check[num] = False
            new_perm = []
            for perm in perms:
                for slot in range(len(perm)+1):
                    # copy original perm
                    inserted_perm = list(perm)
                    # insert
                    inserted_perm.insert(slot, num)
                    # check duplicate perm before insert
                    if needs_check[num] and inserted_perm in new_perm: 
                        continue
                    new_perm.append(inserted_perm)
            needs_check[num] = True
            perms = new_perm
        return perms

test1 = [1, 2, 3]
test2 = [0, 1]
test3 = [1]
test4 = [1, 1, 2]
print(Solution().permuteUnique(test3))
