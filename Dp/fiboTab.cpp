#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
int fibo(int n) {
    if(n == 0 || n == 1) return n;
    if(dp[n] != -1) return dp[n];

    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n = 5;
    vector<int> dp(n + 1, 0);
    dp[0] = 0, dp[1] = 1;
    for(int i = 2 ; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}