class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        auto maxH = max(horizontalCuts[0], h-horizontalCuts.back());
        auto maxV = max(verticalCuts[0], w-verticalCuts.back());
        
        for(int i = 1; i < horizontalCuts.size(); i++){
            maxH = max(maxH, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i = 1; i < verticalCuts.size(); i++){
            maxV = max(maxV, verticalCuts[i]-verticalCuts[i-1]);
        }
        return (long)maxH * maxV % 1000000007;
    }
};