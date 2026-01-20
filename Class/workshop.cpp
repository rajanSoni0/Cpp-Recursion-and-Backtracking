#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> &skill, vector<int> &time, int t, int idx, int k) {
    if(k == 0 && idx >= skill.size()){
        return 0;
    }
    int gain = 0;
    for(int i = idx; i < skill.size(); i++) {
        if(t - time[i] >= 0)
        gain = max(gain, helper(skill, time, t - time[i], i + 1, k - 1) + skill[i]);
        gain = max(gain, helper(skill, time, t, i + 1, k));
    }
    return gain;
}

int main() {
    vector<int> skill = {5,2,1,4,3};
    vector<int> time = {3,4,2,6,2};
    int t = 5, k = 2;
    cout << helper(skill, time, t, 0, k);
}