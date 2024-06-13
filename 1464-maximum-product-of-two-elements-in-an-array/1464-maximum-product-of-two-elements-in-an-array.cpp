class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int p=1, i=2;
        while(i--){
            p*=(pq.top()-1);
            pq.pop();
        }
        return p;
    }
};