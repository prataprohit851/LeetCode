class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> ht;
        for(int i = 0; i < nums.size(); i++){
            auto it = ht.find(nums[i]);
            if(it != ht.end()){
                ht.erase(it);
            }
            else ht.insert(nums[i]);
        }
        return *ht.begin();
    }
};