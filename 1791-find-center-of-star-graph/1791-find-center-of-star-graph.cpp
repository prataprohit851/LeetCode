class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = INT_MIN;
        for(auto ele : edges){
            n = max(n, max(ele[0], ele[1]));
        }
        
        vector<int> ans(n, 0);
        
        for(auto ele : edges){
            ans[ele[0] - 1]++;
            ans[ele[1] - 1]++;
            if(ans[ele[0] - 1] == n-1) return ele[0];
            if(ans[ele[1] - 1] == n-1) return ele[1];
        }
        return -1;
    }
};