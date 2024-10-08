class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();

        vector<vector<int>> res(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int x = min(rowSum[i], colSum[j]);
                rowSum[i]-=x;
                colSum[j]-=x;
                res[i][j]=x;
            }
        }
        return res;
    }
};