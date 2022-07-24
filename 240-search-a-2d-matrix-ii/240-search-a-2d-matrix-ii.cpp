class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int i = 0;
        int j = m[0].size()-1;
        
        while(1){
            if(i >= m.size() || j >= m[0].size())
                return false;
            if(t == m[i][j]) return true;
            if(t > m[i][j]) i++;
            else if(t < m[i][j]) j--;
        }
        return false;
    }
};