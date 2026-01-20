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
    int n = 10;
    dp.assign(n + 1, -1);
    cout << fibo(n);
}