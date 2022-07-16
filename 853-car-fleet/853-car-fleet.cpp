class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> vec;
        int n = position.size();
        for(int i = 0; i < n; i++){
            vec.push_back({position[i], (double)(target-position[i])/speed[i]});
        }
        sort(vec.begin(), vec.end());
        double maxTime = 0;
        int fleet = 0;
        for(int i = n-1; i >= 0; i--){
            double time = vec[i].second;
            if(time > maxTime){
                maxTime = time;
                fleet++;
            }
        }
        return fleet;
    }
};