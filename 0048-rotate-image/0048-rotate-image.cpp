class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
       //take a transpose of the matrix;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto &it: matrix){
            reverse(it.begin(), it.end());
        }
    }
};