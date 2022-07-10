class Solution(object):
    def twoSum(self, s, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        i = 0
        j = len(s)-1
        
        while i<j:
            if s[i]+s[j] == target: return (i+1, j+1)
            elif s[i]+s[j] > target: j -= 1
            else: i += 1
        return ()