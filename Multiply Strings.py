class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1 = num1[::-1]
        num2 = num2[::-1]
        sum = 0
        for i in range(len(num1)):
            for j in range(len(num2)):
                sum += int(num1[i]) * int(num2[j]) * pow(10, i) * pow(10, j)
        return str(sum)





solution = Solution()
num1 = "123"
num2 = "456"
print(solution.multiply(num1, num2))