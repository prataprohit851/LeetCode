class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1, 0, 0, 1);
    }
    bool helper(vector<int>& nums, int i, int j, int P1, int P2, int turn){
        if(i > j){
            return P1 >= P2;
        }
        bool ans = false;
        if(turn == 1){
            ans = helper(nums, i+1, j, P1+nums[i], P2, 2) || helper(nums, i, j-1, P1+nums[j], P2, 2);
        }
        else{
            ans = helper(nums, i+1, j, P1, P2+nums[i], 1) && helper(nums, i, j-1, P1, P2+nums[j], 1);
        }
        return ans;
    }
};