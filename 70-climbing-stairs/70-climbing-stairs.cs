public class Solution {
    public int ClimbStairs(int n) {
        if(n == 1 || n == 2) return n;
        int curr = 0;
        int minone = 1;
        int mintwo = 2;
        for(int i = 2; i < n; i++){
            curr = minone + mintwo;
            minone = mintwo;
            mintwo = curr;
        }
        return curr;
    }
}