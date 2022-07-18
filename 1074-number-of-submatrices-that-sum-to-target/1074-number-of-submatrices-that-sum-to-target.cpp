class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j-1];
        
        unordered_map<int, int> mp;
        int count = 0;
        
        for(int startCol = 0; startCol < n; startCol++){
            for(int endCol = startCol; endCol < n; endCol++){
                mp = {{0, 1}};
                int sum = 0;
                for(int i = 0; i < m; i++){
                    sum += matrix[i][endCol] - ((startCol) ? matrix[i][startCol-1] : 0);
                    count += mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};