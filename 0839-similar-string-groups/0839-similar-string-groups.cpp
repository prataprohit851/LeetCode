class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int sz = strs.size();
        vector<bool> vis(sz, false);
        int groups = 0;
        for(int i = 0; i < sz; i++){
            if(vis[i]) continue;
            groups++;
            dfs(i, strs, vis);
        }
        return groups;
    }
    void dfs(int i, vector<string>& strs, vector<bool>& vis){
        vis[i] = true;
        for(int j = 0; j < strs.size(); j++){
            if(vis[j]) continue;
            if(isSimilar(strs[i], strs[j]))
                dfs(j, strs, vis);
        }
    }
    bool isSimilar(string a, string b){
        int count = 0;
        for(int i = 0; i < a.length(); i++)
            if(a[i] != b[i]) count++;
        return (count == 2 || count == 0);
    }
};