class Solution {
public:
    
    unordered_map<char, vector<char>> mapping = { 
        {'x', {'a', 'e', 'i', 'o', 'u'}},
        {'a', {'e'}                    },
        {'e', {'a', 'i'}               },
        {'i', {'a', 'e', 'o', 'u'}     },
        {'o', {'i', 'u'}               },
        {'u', {'a'}                    }
        };
    
    unordered_map<char, vector<int>> dp;
    
    int MOD = 1e9 + 7;
    
    int countVowelPermutation(int n) {
        dp['x'] = dp['a'] = dp['e'] = dp['i'] = dp['o'] = dp['u'] = vector<int> (n + 1);
        return helper(n, 'x');
    }
    
    int helper(int size, char prev){
        if(size == 0) return 1;
        if(dp[prev][size]) return dp[prev][size];
        
        for(auto ele : mapping.at(prev)){
            dp[prev][size] = (dp[prev][size] + helper(size-1, ele)) % MOD;
        }
        
        return dp[prev][size];
    }
};