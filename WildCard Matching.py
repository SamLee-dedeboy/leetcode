class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if p == s: return True
        if self.all_stars(p): return True
        if p == '' or s == '': return False
        dp = [[False]*(len(s)+1) for i in range(len(p)+1)]
        dp[0][0] = True
        for p_index in range(1, len(p)+1):
            if p[p_index-1] == "?": 
                for s_index in range(1, len(s)+1):
                    dp[p_index][s_index] = dp[p_index-1][s_index-1]
                continue

            if p[p_index-1] == "*":
                s_index = 1
                # find previous match pos
                while not dp[p_index - 1][s_index - 1] and s_index < len(s) + 1:
                    s_index += 1
                
                # if * matches nothing 
                dp[p_index][s_index - 1] = dp[p_index - 1][s_index - 1]

                # if * matches everything
                while s_index < len(s) + 1:
                    dp[p_index][s_index] = True
                    s_index += 1
                continue

            # normal char
            else:
                for s_index in range(1, len(s)+1):
                    dp[p_index][s_index] = dp[p_index-1][s_index-1] and p[p_index-1] == s[s_index-1]
                continue
        return dp[len(p)][len(s)]

    def all_stars(self, p):
        if len(p) == 0: return False
        for c in p:
            if c != "*": return False
        return True





solution = Solution()

s1 = "123abcdsadsadsasdsaab1"
p1 = "???*ab?*ab1"

# True
s2 = "abcabczzzde"
p2 = "*abc???de*"

# True
s3 = "adceb"
p3 = "*a*b"

# False
s4 = "acdcb"
p4 = "a*c?b"

# False
s5 = "mississippi"
p5 = "m??*ss*?i*pi"

# True
s6 = "mississippi"
p6 = "m**pi"

# True 
s7 = "mississippi"
p7 = "m*?pi"

# False 
s8 = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb"
p8 = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"

# True 
s9 = "abb"
p9 = "**??"

# True 
s0 = "baaaa"
p0 = "*aaa"

# print(solution.find_all_substring("ababa", "ba", 0))
print(s0)
print(p0)
import time
t1 = time.time()
print(solution.isMatch("aa", "*"))
t2 = time.time()
print(t2 - t1)
