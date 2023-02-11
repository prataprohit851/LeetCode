class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        map<int, vector<int>> red;
        map<int, vector<int>> blue;
        for(int i = 0; i < redEdges.size(); i++){
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i = 0; i < blueEdges.size(); i++){
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        int dist = 1;
        vector<int> ans(n, INT_MAX);
        vector<bool> visitedBlue(n, false);
        vector<bool> visitedRed(n, false);
        queue<pair<int, string>> q;
        visitedRed[0] = true;
        visitedBlue[0] = true;
        for(auto x : red[0]){
            q.push({x, "RED"});
            visitedRed[x] = true;
            ans[x] = dist;
        }
        for(auto x : blue[0]){
            q.push({x, "BLUE"});
            visitedBlue[x] = true;
            ans[x] = dist;
        }
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front().first;
                string col = q.front().second;
                q.pop();
                if(col == "RED"){
                    for(auto x : blue[node]){
                            if(!visitedBlue[x]){
                            visitedBlue[x] = true;
                            ans[x] = min(ans[x], dist+1);
                            q.push({x, "BLUE"});
                        }
                    }
                }
                else if(col == "BLUE"){
                    for(auto x : red[node]){
                            if(!visitedRed[x]){
                            visitedRed[x] = true;
                            ans[x] = min(ans[x], dist+1);
                            q.push({x, "RED"});
                        }
                    }
                }
            }
            dist++;
        }
        ans[0] = 0;
        for(auto &x : ans) if(x == INT_MAX) x = -1;
        return ans;
    }
};


// class Solution {
//     typedef pair<int,int> ii;
//     const int RED = 1, BLUE = 2;

// public:
//     vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
//         unordered_map<int, vector<int>> rg;
//         unordered_map<int, vector<int>> bg;

//         for(auto e : redEdges){
//             rg[e[0]].push_back(e[1]);
//         }

//         for(auto e : blueEdges){
//             bg[e[0]].push_back(e[1]);
//         }

//         queue<ii> q;
//         vector<int> ans(n, INT_MAX);
//         vector<bool> visitedRed(n,false);
//         vector<bool> visitedBlue(n,false);
//         vector<bool> visited(n,false);
//         int dist = 1;
//         visitedRed[0] = true;
//         visitedBlue[0] = true;
//         // visited[0] = true;
        

//         // initialize q with neighbors of 0 along with their edge color
//         for(auto nbr : rg[0]){
//             visitedRed[nbr] = true;
//             // visited[nbr] = true;
//             ans[nbr] = dist;
//             q.push(ii(nbr,RED));
//         }

//         for(auto nbr : bg[0]){
//             visitedBlue[nbr] = true;
//             // visited[nbr] = true;
//             ans[nbr] = dist;
//             q.push(ii(nbr,BLUE));
//         }

//         while(!q.empty()){
//             int sz = q.size();
//             for(int i = 0 ; i<sz ; i++){
//                 int node = q.front().first;
//                 int color = q.front().second;
//                 // cout<<"Curr Node is : "<<node<<" with color: "<<color<<endl;
//                 q.pop();

//                 if(color == RED){
//                     for(auto nbr : bg[node]){
//                         if(!visitedBlue[nbr]){
//                             visitedBlue[nbr] = true;
//                             // cout<<"visited "<<nbr<<" node where the ans was : "<<ans[nbr]<<endl;
//                             visited[nbr] = true;
//                             ans[nbr] = min(ans[nbr], dist+1);
//                             q.push(ii(nbr, BLUE));
//                         }
//                     }
//                 }else if(color == BLUE){
//                     for(auto nbr : rg[node]){
//                         if(!visitedRed[nbr]){
//                             visitedRed[nbr] = true;
//                             // cout<<"visited "<<nbr<<" node where the ans was : "<<ans[nbr]<<endl;
//                             ans[nbr] = min(ans[nbr], dist+1);
//                             q.push(ii(nbr, RED));
//                         }
//                     }
//                 }
//             }
//             dist++;
//         }
//         ans[0] = 0;
//         for(int i = 0 ; i<n ; i++){
//             if(ans[i] == INT_MAX){
//                 ans[i] = -1;
//             }
//         }
//         return ans;
//     }
// };