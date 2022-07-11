class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int row = mat.size()-1;
        int col = 0;
        
        while(col < mat[0].size()-1){
            vector<int> num;
            if(row == 0) col++;
            else row--;

            int i = row;
            int j = col;
            
            while(i < mat.size() && j < mat[0].size())
                num.push_back(mat[i++][j++]);

            sort(num.begin(), num.end());
            
            i = row;
            j = col;
            int ind = 0;
            
            while(i < mat.size() && j < mat[0].size())
                mat[i++][j++] = num[ind++];
        }
        return mat;
    }
};