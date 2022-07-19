class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        int lastVal = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            lastVal += nums[i];
            if(lastVal == k) 
                count++;
            
            if(ht.find(lastVal - k) != ht.end())
                count += ht[lastVal - k];
                
            ht[lastVal]++;
        }
        return count;
    }
};