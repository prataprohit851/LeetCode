class Solution {
    fun minMoves2(nums: IntArray): Int {
        nums.sort()
        var left = 0
        var right = nums.size-1
        var mid = nums.size /2
        var count = 0
        while (left != mid || right != mid){
            if (left != mid) {count += nums[mid]-nums[left++]}
            if (right != mid) {count += nums[right--]-nums[mid]}
        }
        return count
    }
}