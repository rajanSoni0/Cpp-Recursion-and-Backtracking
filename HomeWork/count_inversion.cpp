#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
  public:
  
    int count(vector<int> &arr, vector<int> &temp, int start, int mid, int end) {
        int i = start, j = mid + 1, k = start;
        int c = 0;
        while(i <= mid && j <= end) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                c += mid - i + 1;
            }
        }
        while(i <= mid) {
            temp[k++] = arr[i++];
        }
        while(j <= end) {
            temp[k++] = arr[j++];
        }
        
        while(start <= end) {
            arr[start++] = temp[start];
        }
        return c;
    }
    
    int divide(vector<int> &arr, vector<int> &temp, int start, int end) {
        if(start >= end) return 0;
        int c = 0;
        int mid = start + (end - start) / 2;
        c += divide(arr, temp, start, mid);
        c += divide(arr, temp, mid + 1, end);
        c += count(arr, temp, start, mid, end);
        return c;
    }
    int inversionCount(vector<int> &arr) {
        int c = 0;
        vector<int> temp(arr.size(), 0);
        int n = arr.size();
        return divide(arr, temp, 0, n - 1);
        
    }
};