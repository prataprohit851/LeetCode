class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int bucket = capacity;
        int steps = 0;
        for(int i = 0; i < plants.size(); i++){
            if(bucket >= plants[i]){
                bucket -= plants[i];
                steps++;
            }
            else{
                steps += (2*i) + 1;
                bucket = capacity;
                bucket -= plants[i];
            }
        }
        return steps;
    }
};