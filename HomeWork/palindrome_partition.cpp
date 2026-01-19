#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<bool>> pal;
    void palindrome(string &s) {
        int n = s.size();
        pal.resize(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && (len == 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
    }
    void helper(string &s, int i, vector<string> &temp) {
        if(i >= s.size()) {
            ans.push_back(temp);
            return;
        }
        for(int j = i; j < s.size(); j++) {
            if(pal[i][j]) {
                temp.push_back(s.substr(i, j - i + 1));
                helper(s, j + 1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        palindrome(s);
        helper(s, 0, temp);
        return ans;
    }
};