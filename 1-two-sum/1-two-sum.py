class Solution(object):
    def twoSum(self, nums, target):
        sett = {}
        for i in range(len(nums)):
            rem =  target - nums[i]
            if rem in sett:
                return [i, sett[rem]]
            else:
                sett[nums[i]] = i
        
        