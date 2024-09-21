class Solution {
public:
    static bool comparator(vector<int>& v1, vector<int>& v2) {
        if (v1[0] != v2[0])
            return v1[0] < v2[0]; 
        return v1[1] < v2[1];
    }
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        sort(matches.begin(), matches.end(), comparator);
        map<int, int> looser;
        for (auto it : matches) {
            cout << it[0] << " " << it[1] << endl;
            looser[it[1]]++;
        }
        int temp=-1;
        for (auto it : matches) {
            if(it[0]==temp) continue;
            if (looser.find(it[0]) == looser.end())
                ans[0].push_back(it[0]);
            temp=it[0];
        }
        for (auto it : looser) {
            if (it.second == 1)
                ans[1].push_back(it.first);
        }
        return ans;
    }
};