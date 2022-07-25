class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t) {
        if(!n.size()) return {-1, -1};
        int i = 0;
        int j = n.size()-1;
        vector<int> ans = {-1, -1};
        
        while(i < j){
            int m = i + (j - i)/2;
            if(n[m] < t) i = m + 1;
            else j = m;
        }
        if(n[i] != t) return ans;
        
        ans[0] = i;

        j = n.size() - 1;
        while(i < j){
            int m = i + (j - i)/2 + 1;
            if(n[m] > t) j = m - 1;
            else i = m;
        }
        ans[1] = j;
        return ans;
    }
};