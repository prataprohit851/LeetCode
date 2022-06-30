class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        int mid = nums.size()/2;
        int count = 0;
        while(left != mid || right != mid){
            if(left != mid) count += nums[mid]-nums[left++];
            if(right != mid) count += nums[right--]-nums[mid];
        }
        return count;
    }
};