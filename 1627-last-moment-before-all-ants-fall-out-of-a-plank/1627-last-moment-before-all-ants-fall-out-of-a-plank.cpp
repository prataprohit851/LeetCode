class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l = (left.size() == 0) ? 0 : *max_element(left.begin(), left.end());
        int r = (right.size() == 0) ? INT_MAX : *min_element(right.begin(), right.end());
        cout<<l<<" "<<r<<endl;
        return (r == INT_MAX) ? l : max(l,n-r);
        // if return ;
        // else return 
    }
};