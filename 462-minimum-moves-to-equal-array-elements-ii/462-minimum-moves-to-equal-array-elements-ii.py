class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        left = 0
        right = len(nums)-1
        mid = floor(len(nums)/2)
        count = 0
        while (left != mid or right != mid):
            if left != mid:
                count += nums[mid]-nums[left]
                left += 1
            if right != mid:
                count += nums[right]-nums[mid]
                right -= 1
            
        return count