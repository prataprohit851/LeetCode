class Solution {
public:
    int maxConsecutiveAnswers(string ak, int k) {
        int i = 0, j = 0;
        int ans = 0;
        int count = 0;
        while(j < ak.length()){
            if(ak[j] == 'F') count++;
            if(count > k){
                
                while(count > k){
                    if(ak[i] == 'F') count--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        i = 0, j = 0, count = 0;
        while(j < ak.length()){
            if(ak[j] == 'T') count++;
            if(count > k){
                
                while(count > k){
                    if(ak[i] == 'T') count--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};