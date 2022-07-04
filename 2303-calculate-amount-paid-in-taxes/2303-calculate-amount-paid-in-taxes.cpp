class Solution {
public:
    double calculateTax(vector<vector<int>>& br, int income) {
        double taxPaid = 0;
        int i = 0;
        
        for(int i = br.size()-1; i > 0; i--){
            br[i][0] -= br[i-1][0];
            cout<<br[i][0]<<endl;
        }
        
        while(income != 0 && i < br.size()){
            if(income <= br[i][0]){
                taxPaid += ((double)income * br[i][1]) / 100;
                income = 0;
            }
            else{
                income -= br[i][0];
                taxPaid += ((double)br[i][0] * br[i][1]) / 100;
            }
            i++;
        }
        return taxPaid;
    }
};