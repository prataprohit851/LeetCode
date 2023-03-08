class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minA = 1;
        int maxA = *max_element(piles.begin(), piles.end());
        while(minA <= maxA){
            long long midT = (minA + maxA)/2;
            long long t = 0;
            for(auto v : piles){
                t += ceil(1.0*v/midT);
            }
            if(t > h){
                minA = midT+1;
            }
            else maxA = midT-1;
        }
        return minA;
    }
};