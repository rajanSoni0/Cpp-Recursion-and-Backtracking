#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> val;
    int permut(int i)
    {
        if (i <= 0)
            return 1;
        if (val[i] != -1)
            return val[i];
        return val[i] = permut(i - 1) * i;
    }
    string getPermutation(int n, int k)
    {
        string ans;
        val.resize(100000, -1);
        k--;
        vector<bool> visited(n + 1, false);
        while (ans.size() != n)
        {
            int left = n - ans.size() - 1;
            int per = permut(left);
            int jump = k / per;
            k = k % per;
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i])
                {
                    if (jump == 0)
                    {
                        visited[i] = true;
                        ans += to_string(i);
                        break;
                    }
                    jump--;
                }
            }
        }
        return ans;
    }
};