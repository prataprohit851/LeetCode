class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        int ind = 0;

        for(int i = 1; i <= target[target.size()-1]; i++){
            if(target[ind] == i){
                st.push(i);
                ans.push_back("Push");
                ind++;
            }
            else if(st.empty() || st.top() < target[ind]){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};