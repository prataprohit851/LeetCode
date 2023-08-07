class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n-1;

        while(low <= high){
            int midCol = low + (high - low) / 2;

            int maxRowEle = 0;
            for(int i = 0; i < m; i++)
                if(mat[maxRowEle][midCol] < mat[i][midCol])
                    maxRowEle = i;
            
            int L = (midCol == 0) ? INT_MIN : mat[maxRowEle][midCol-1];
            int R = (midCol == n-1) ? INT_MIN : mat[maxRowEle][midCol+1];

            if(mat[maxRowEle][midCol] > max(L, R))
                return {maxRowEle, midCol};

            if(mat[maxRowEle][midCol] < L)
                high = midCol - 1;
            else
                low = midCol + 1;
            
        }
        return {-1, -1};
    }
};

// [[1,2,3,4,5,6,7,8],[2,3,4,5,6,7,8,9],[3,4,5,6,7,8,9,10],[4,5,6,7,8,9,10,11]]
// [[1,4],[3,2]]
// [[10,20,15],[21,30,14],[7,16,32]]
// [[1,5,10,5,1],[6,7,8,7,6],[4,3,2,1,3]]
// [[7,8,9,10,11,12,13],[6,5,4,3,2,1,14]]