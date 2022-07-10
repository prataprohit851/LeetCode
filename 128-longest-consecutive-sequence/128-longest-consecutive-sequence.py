class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ht = set(nums)
        count = 0
        for i in nums:
            if i-1 not in ht: 
                length = 0
                while(i+length in ht):
                    length += 1
                count = max(count, length)
        return count