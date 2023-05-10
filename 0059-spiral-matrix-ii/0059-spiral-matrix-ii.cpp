class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int num = 1;
        vector<vector<int>> ans(n, vector<int> (n, 1));
        int topRow = 0;
        int bottomRow = n-1;
        int leftCol = 0;
        int rightCol = n-1;
        
        while(topRow <= bottomRow && rightCol >= leftCol){
        
            for(int j = leftCol; j <= rightCol; j++){
                ans[topRow][j] = num;
                num++;
            }
            topRow++;

            for(int i = topRow; i <= bottomRow; i++){
                ans[i][rightCol] = num;
                num++;
            }
            rightCol--;

            for(int j = rightCol; j >= leftCol; j--){
                ans[bottomRow][j] = num;
                num++;
            }
            bottomRow--;

            for(int i = bottomRow; i >= topRow; i--){
                ans[i][leftCol] = num;
                num++;
            }
            leftCol++;
            n--;
        }
   
        
        return ans;
    
    }
};

