#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    unordered_set<string> st;
    int n;
    bool solve(string &s, int idx) {
        if(idx >= n) return true;

        for(int l = 0; l < n; l++) {
            if(st.find(s.substr(idx, l)) != st.end() && solve(s, idx + l)) {
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto &str : wordDict) {
            st.insert(str);
        }
        if(st.find(s) != st.end()) return true;
        return solve(s, 0);
    }
};