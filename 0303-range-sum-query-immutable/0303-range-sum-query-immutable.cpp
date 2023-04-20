class NumArray {
public:
    vector<int> n;
    NumArray(vector<int>& nums) {
        n = nums;
        for(int i = 1; i < nums.size(); i++){
            n[i] += n[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return n[right] - ((left-1 == -1) ? 0 : n[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */