// class Solution {
// public:
//     int largestPathValue(string colors, vector<vector<int>>& edges) {
//         int n = colors.length();
//         map<int, vector<int>> mp;
//         map<int, vector<int>> col;
//         for(auto x : edges){
//             mp[x[0]].push_back(x[1]);
//         }
//         int ans = INT_MIN;
//         for(int i = 0; i < n; i++){
//             vector<int> temp(n, 0);
//             ans = max(ans, dfs(i, mp, col, temp, colors));
//         }
//         return ans;
//     }
//     int dfs(int i, map<int, vector<int>>& ed, map<int, vector<int>>& col, vector<int>& temp, string colors){
//         if(col.find(i) != col.end()) return *max_element(col[i].begin(), col[i].end());
//         temp[colors[i]-'a']++;
//         for(auto x : ed[i]){
//             dfs(x, ed, col, temp, colors);
//         }
//         col[i] = temp;
//         return *max_element(temp.begin(), temp.end());
//     }
// };

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;

        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int answer = 0, nodesSeen = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            answer = max(answer, ++count[node][colors[node] - 'a']);
            nodesSeen++;

            for (auto& neighbor : adj[node]) {
                for (int i = 0; i < 26; i++) {
                    // Try to update the frequency of colors for neighbor to include paths
                    // that use node->neighbor edge.
                    count[neighbor][i] = max(count[neighbor][i], count[node][i]);
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return nodesSeen < n ? -1 : answer;
    }
};