class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& m, int k) {
        int ans = INT_MIN;
        int rows = m.size();
        int cols = m[0].size();
        for(int i = 0; i < cols; i++){
            vector<int> r(rows);
            for(int j = i; j < cols; j++){
                for(int l = 0; l < rows; l++){
                    r[l] += m[l][j];
                }
                set<int> nums = {0};
                int currSum = 0;
                for(int sum : r){
                    currSum += sum;
                    auto it = nums.lower_bound(currSum - k);
                    if(it != nums.end()){
                        ans = max(ans, currSum - *it);
                    }
                    nums.insert(currSum);
                }
            }
        }
        return ans;
    }
};