class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i = 0, j = 0; i < mat.size(); i++, j++){
            ans += mat[i][j];
        }
        for(int i = mat.size()-1, j = 0; i >= 0; i--, j++){
            ans += mat[i][j];
        }
        return (mat.size() % 2 == 0) ? ans : ans -= mat[mat.size()/2][mat.size()/2];
    }
};