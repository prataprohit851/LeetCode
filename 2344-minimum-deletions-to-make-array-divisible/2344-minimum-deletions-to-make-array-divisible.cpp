class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int gcdNum = numsDivide[0];
        
        for(auto ele : numsDivide){
            gcdNum = gcd(gcdNum, ele);
        }
        
        sort(nums.begin(), nums.end());
        // cout<<gcdNum;
        for(int i = 0; i < nums.size(); i++){
            if(gcdNum % nums[i] == 0) return i;
        }
            
        return -1;
    }
    
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
};