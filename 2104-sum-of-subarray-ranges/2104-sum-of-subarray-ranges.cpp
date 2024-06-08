#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define ll long long
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        ll totalSum=0;
        for(int i=0; i<n; i++){
            int minVal=nums[i], maxVal=nums[i];
            for(int j=i; j<n; j++){
                maxVal=max(maxVal, nums[j]);
                minVal=min(minVal, nums[j]);
                ll diff=maxVal-minVal;
                totalSum+=diff;
            }
        }
        return totalSum;
    }
};