class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0;
        int h = nums.size()-1;
        while(l <= h){
            int m = h-(h-l)/2;
            if(t < nums[m]) h = m-1;
            else if(t > nums[m]) l = m+1;
            else return m;
        }
        return -1;
    }
};