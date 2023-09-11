class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> group;
        vector<vector<int>> ans;
        for(int i = 0; i < groupSizes.size(); i++){
            group[groupSizes[i]].push_back(i);
            if(group[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back(group[groupSizes[i]]);
                group[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};