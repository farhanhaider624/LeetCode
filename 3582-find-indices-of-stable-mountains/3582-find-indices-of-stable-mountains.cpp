class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int t) {
        vector<int> ans;
        for(int i=1; i<height.size(); i++){
            if(height[i-1]>t) ans.push_back(i);
        }
        return ans;
    }
};