#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int maxi=-1, mini=-1;
        int s=nums.size();
        for(int r=0, l=0; r<s; r++){
            int x=nums[r];
            if (x<minK ||x>maxK){
                l=r+1; 
                continue;
            }
            if (x==maxK) maxi=r;
            if (x==minK) mini=r;
            ans+=max((min(maxi, mini)-l+1),0);
        }
        return ans;
    }
};