class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=1; i<arr.size(); i++){
            arr[i]=arr[i]^arr[i-1];
        }
        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int temp;
            if(l-1<0) temp=arr[r];
            else temp=arr[r]^arr[l-1];
            ans.push_back(temp);
        }
        return ans;
    }
};