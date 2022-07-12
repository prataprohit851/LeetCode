class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int equal = 0;
        for(auto ele : nums){
            if(ele < pivot) ans.push_back(ele);
            else if(ele == pivot) equal++;
        }
        while(equal--) ans.push_back(pivot);
        for(auto ele : nums){
            if(ele > pivot) ans.push_back(ele);
        }
        return ans;
    }
};