class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int ind = 2; 
        int pdiff = nums[1] - nums[0];
        int size = (pdiff == 0) ? 1 : 2;
        while(ind < nums.size()){
            int t = nums[ind] - nums[ind-1];
            if((t > 0 && pdiff <= 0) || (t < 0 && pdiff >= 0)){
                size++;
                pdiff = t;
            } 
            ind++;
        }
        return size;
    }
};