class Solution {
public:
    void Reverse(int s, int e, vector<int> &nums){
        while(s<=e){
            int temp=nums[s];
            nums[s]=nums[e];
            nums[e]=temp;
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==n) return;
        Reverse(0, n-k-1, nums);
        Reverse(n-k, n-1, nums);
        Reverse(0, n-1, nums);
    }
};