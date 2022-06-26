class Solution {
public:
    int maxScore(vector<int>& CP, int k) {
        int j = 0;
        int sum = 0;
        j = CP.size()-k-1;
        
        for(int t = j+1; t < CP.size(); t++){
            sum += CP[t];
        }
        int i = 0;
        int total = sum;
        while(j < CP.size()-1){
            total = total+CP[i]-CP[j+1];
            sum = max(sum, total);
            j++;
            i++;
        }
        return sum;
    }
};