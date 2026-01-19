#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;
        for(auto &str : wordDict) {
            st.insert(str);
        }
        if(st.find(s) != st.end()) return true;
        vector<bool>dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j + i <= n; j++) {
                string temp = s.substr(i, j);
                if(st.count(temp) && dp[i + j]) {
                    dp[i] = true;
                }
            } 
        }
        return dp[0];
    }

};