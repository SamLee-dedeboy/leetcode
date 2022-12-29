class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        group = {}
        for str in strs:
            bit_array = [0]*26
            for c in str:
                bit_array[ord(c) - ord('a')] += 1
            index = ''.join(sorted(str))
            if index not in group:
                group[index] = []
            group[index].append(str)
        return list(group.values())
    
            

test1 = ["eat","tea","tan","ate","nat","bat"]
test2 = [""]
test3 = ["a"]
test4 = ["ddddddddddg","dgggggggggg"]
test5 = ["bd","aacc"]
print(Solution().groupAnagrams(test5))
            

    