#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++)
            v.push_back({nums[i], i});
        
        mergeSort(v, 0, n - 1, count);
        return count;
    }
    
    void mergeSort(vector<pair<int,int>>& v, int left, int right, vector<int>& count) {
        if(left >= right) return;
        
        int mid = (left + right) / 2;
        mergeSort(v, left, mid, count);
        mergeSort(v, mid + 1, right, count);
        merge(v, left, mid, right, count);
    }
    
    void merge(vector<pair<int,int>>& v, int left, int mid, int right, vector<int>& count) {
        vector<pair<int,int>> temp;
        int i = left, j = mid + 1;
        int rightCount = 0;
        
        while(i <= mid && j <= right) {
            if(v[j].first < v[i].first) {
                temp.push_back(v[j]);
                rightCount++;
                j++;
            } else {
                count[v[i].second] += rightCount;
                temp.push_back(v[i]);
                i++;
            }
        }
        
        while(i <= mid) {
            count[v[i].second] += rightCount;
            temp.push_back(v[i]);
            i++;
        }
        
        while(j <= right) {
            temp.push_back(v[j]);
            j++;
        }
        
        for(int k = left; k <= right; k++)
            v[k] = temp[k - left];
    }
};