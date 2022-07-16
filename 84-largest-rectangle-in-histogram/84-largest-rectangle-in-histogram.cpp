class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ps;
        vector<int> ns;
        int n = heights.size();
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            while(st.size() && heights[st.top()] >= heights[i]) st.pop();
                
            if(st.size() == 0) ps.push_back(-1);
            else ps.push_back(st.top());
            st.push(i);
        }
        while(st.size()) st.pop();
        
        for(int i = n-1; i >= 0; i--){
            while(st.size() && heights[st.top()] >= heights[i]) st.pop();
                
            if(st.size() == 0) ns.push_back(n);
            else ns.push_back(st.top());
            st.push(i);
        }
        reverse(ns.begin(), ns.end());
        
        int maxAr = 0;
        for(int i = 0; i < n; i++){
            maxAr = max(maxAr, (ns[i]-ps[i]-1) * heights[i]);
        }
        return maxAr;
    }
};