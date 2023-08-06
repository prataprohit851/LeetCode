class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low + (high - low) / 2;
            int sum = 0;
            for(auto x : nums){
                sum += ceil(1.0*x/mid);
            }
            if(sum > threshold){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};