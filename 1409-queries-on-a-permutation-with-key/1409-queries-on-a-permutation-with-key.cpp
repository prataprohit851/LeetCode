class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans;
        vector<int> perm;
        for(int i = 1; i <= m; i++){
            perm.push_back(i);
        }
        
        for(int i = 0; i < queries.size(); i++){
            int num = queries[i];
            int ind = 0;
            while(perm[ind] != num) ind++;
            ans.push_back(ind);
            perm.erase(perm.begin()+ind);
            perm.insert(perm.begin(), num);
        }
        return ans;
    }
};