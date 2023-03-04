class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int minInd = 0;
        int maxInd = 0;
        int start = 0;
        bool minF = false;
        bool maxF = false;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK){
                minF = false;
                maxF = false;
                start = i+1;
            }
            if(nums[i] == minK){
                minInd = i;
                minF = true;
            }
            if(nums[i] == maxK){
                maxInd = i;
                maxF = true;
            }
            if(minF && maxF){
                count = count + min(minInd,maxInd) - start + 1;
            }
        }
        return count;
    }
};