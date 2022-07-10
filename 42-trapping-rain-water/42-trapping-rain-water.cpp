class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftBound(n, 0);
        vector<int> rightBound(n, 0);
        
        for(int i = 1; i < n; i++){
            leftBound[i] = max(leftBound[i-1], height[i-1]);
            rightBound[n-i-1] = max(rightBound[n-i], height[n-i]);
        }
        int water = 0;
        for(int i = 0; i < n; i++){
            int temp = min(leftBound[i], rightBound[i]) - height[i];
            if(temp > 0) water += temp;
        }
        return water;
    }
};