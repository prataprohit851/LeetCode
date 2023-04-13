class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int m = 0;
        stack<int> st;
        for(int i = 0; i < popped.size(); i++){
            st.push(pushed[i]);
            while(st.size() && st.top() == popped[m]){
                st.pop();
                m++;
            }
        }
        return (!st.size()) ? true : false;
    }
};