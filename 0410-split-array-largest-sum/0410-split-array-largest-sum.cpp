class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            int partitions = findPartitions(nums, mid);
            if(partitions > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    int findPartitions(vector<int>& nums, int k){
        int arr = 1;
        int sum = 0;
        for(auto x : nums){
            if(x + sum <= k){
                sum += x;
            }
            else{
                sum = x;
                arr++;
            }
        }
        return arr;
    }
};