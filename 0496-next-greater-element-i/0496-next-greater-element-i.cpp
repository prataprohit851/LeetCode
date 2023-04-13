class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        // vector<int> vec(nums2.size(), -1);
        map<int, int> mp;
        for(int i = nums2.size()-1; i >= 0; i--){
            if(!st.size()){
                st.push(nums2[i]);
                mp[nums2[i]] = -1;
            } 
            else{
                while(st.size() && st.top() <= nums2[i]) st.pop();
                if(st.size()) mp[nums2[i]] = st.top();
                else mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
        }
        // for(auto x : mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        for(auto& x : nums1){
            x = mp[x];
        }
        return nums1;;
    }
};