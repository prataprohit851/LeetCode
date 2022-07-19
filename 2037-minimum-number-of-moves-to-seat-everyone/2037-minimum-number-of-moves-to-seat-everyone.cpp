class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        priority_queue<int> ss;
        priority_queue<int> st;
        int n = seats.size();
        for(int i = 0; i < n; i++){
            ss.push(seats[i]);
            st.push(students[i]);
        }
        int ans = 0;
        while(ss.size() != 0){
            ans += abs(ss.top() - st.top());
            ss.pop();
            st.pop();
        }
        return ans;
    }
};

// class Solution {
// public:
//     int minMovesToSeat(vector<int>& seats, vector<int>& students) {
//         sort(seats.begin(), seats.end());
//         sort(students.begin(), students.end());
//         int n = seats.size();
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//             ans += abs(students[i] - seats[i]);
        
//         return ans;
//     }
// };