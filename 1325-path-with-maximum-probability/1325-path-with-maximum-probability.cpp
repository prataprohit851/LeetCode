// class Solution {
// public:
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//         map<int, vector<pair<int, double>>> mp;
//         for(int i = 0; i < edges.size(); i++){
//             mp[edges[i][0]].push_back({edges[i][1], succProb[i]});
//             mp[edges[i][1]].push_back({edges[i][0], succProb[i]});
//         }
//         queue<pair<int, double>> q;
//         vector<bool> visited(n, false);
//         for(int i = 0; i < mp[start].size(); i++){
//             q.push({mp[start][i].first, mp[start][i].second});
//         }
//         double ans = 0;
//         while(q.size()){
//             auto tp = q.front();
//             q.pop();
//             if(tp.first == end) ans = max(ans, tp.second);
//             else{
//                 for(int i = 0; i < mp[tp.first].size(); i++){
//                     cout<<mp[tp.first][i].first<<endl;
//                     if(!visited[mp[tp.first][i].first]){
//                         visited[mp[tp.first][i].first] = true;
//                         q.push({mp[tp.first][i].first, mp[tp.first][i].second * tp.second});
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
      //we have created an adjancey list to store the graph it is of int,double as proba is in double  
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

      // we need dist array to store probability till that node with max
        vector<double> dist(n, 0.0);
        // probabilty of source is 1
        dist[start] = 1.0;
        //for traversal we will use queue
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {

            int curr = q.front();
            q.pop();
            // from q top node to all its adjacent nodes
            for (auto it : adj[curr]) {

                int nextNode = it.first;
                double prob = it.second;
               //checking new prob with all option
                double newProb = dist[curr] * prob;
                // storin the max one
                if (newProb > dist[nextNode]) {
                    dist[nextNode] = newProb;
                    q.push(nextNode);
                }
            }
        }
        //return prob to reach end
        return dist[end];
    }
};