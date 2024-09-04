class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i=0; i<A.size(); i++){
            mp[A[i]]++;
            mp[B[i]]++;
            int cnt=((i+1)*2)-mp.size();
            res.push_back(cnt);
        }
        return res;
    }
};