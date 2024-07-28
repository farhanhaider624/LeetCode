class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for(auto &it: edges){
            int i = it[0];
            int j = it[1];
            int wt = it[2];
            matrix[i][j]=wt;
            matrix[j][i]=wt;
        }
        for(int i=0; i<n; i++){
            matrix[i][i]=0;
        }
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(matrix[i][via]!=1e9 && matrix[via][j]!=1e9){
                        int temp = matrix[i][via]+matrix[via][j];
                        if(temp<matrix[i][j]){
                            matrix[i][j]=temp;
                        }
                    }
                }
            }
        }
        int city = 0;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(matrix[i][j]<=distanceThreshold){
                        cnt++;
                }
            }
            if(cnt<=mini){
                mini = cnt;
                city=i;
            }
        }
        return city;
    }
};