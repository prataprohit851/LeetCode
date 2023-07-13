class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int l = 0;
        int h = matrix.size()-1;
        while(l < h){
            int m = (l-h)/2+h;
            if(t < matrix[m][0]) h = m-1;
            else l = m;
        }

        int row = h;
        l = 0;
        h = matrix[0].size()-1;

        while(l < h){
            int m = (l-h)/2+h;
            cout<<m<<endl;
            if(matrix[row][m] == t) return true;
            if(t < matrix[row][m]) h = m-1;
            else l = m;
        }

        return matrix[row][h] == t;
    }
};