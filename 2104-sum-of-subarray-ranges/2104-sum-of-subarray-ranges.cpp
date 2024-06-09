#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define ll long long
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        ll totalSum=0;
        stack<int> s;
        for(int i=0; i<=n; i++){
            while(!s.empty() && (i==n || nums[s.top()]>=nums[i])){
                int mid=s.top();
                s.pop();
                int l= s.size()==0?-1:s.top();
                totalSum-=(ll)nums[mid]*(i-mid)*(mid-l);
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=0; i<=n; i++){
            while(!s.empty() && (i==n || nums[s.top()]<=nums[i])){
                int mid=s.top();
                s.pop();
                int l=s.size()==0?-1:s.top();
                totalSum+=(ll)nums[mid] * (i-mid)*(mid-l);
            }
            s.push(i);
        }
        return totalSum;
    }
};