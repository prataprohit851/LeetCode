class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int minNum = INT_MAX;
        for(auto num : nums){
            if(num % 2 == 1) num *= 2;
            q.push(num);
            minNum = min(minNum, num);
        }
        int diff = INT_MAX;
        while(q.top() % 2 == 0){
            int mx = q.top();
            q.pop();
            diff = min(diff, mx-minNum);
            minNum = min(minNum, mx/2);
            q.push(mx/2);
        }
        return min(diff, q.top()-minNum);
    }
};