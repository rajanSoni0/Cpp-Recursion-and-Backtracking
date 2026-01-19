#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    unordered_set<string> st;
    int n;
    vector<int> dp;
    bool solve(string &s, int idx) {
        if(idx >= n) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int l = 0; l + idx <= n; l++) {
            if(st.count(s.substr(idx, l)) && solve(s, idx + l)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto &str : wordDict) {
            st.insert(str);
        }
        if(st.find(s) != st.end()) return true;
        dp.resize(n, -1);
        return solve(s, 0);
    }
};