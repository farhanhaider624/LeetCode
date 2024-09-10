class Solution {
public:
    vector<int> parent, Size;
    int findPar(int i){
        if(parent[i]==i) return i;
        return parent[i]=findPar(parent[i]);
    }
    void UnionBySize(int u, int v){
        int pu=findPar(u);
        int pv=findPar(v);
        if(pu!=pv){
            if(Size[pu]>=Size[pv]){
                parent[pv]=pu;
                Size[pu]+=Size[pv];
            }
            else{
                parent[pu]=pv;
                Size[pv]+=Size[pu];
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        Size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
        vector<int> ans;
        for(auto it:edges){
            int pu=findPar(it[0]);
            int pv=findPar(it[1]);
            if(pu==pv){
                if(ans.size()==2){
                    ans.pop_back();
                    ans.pop_back();
                }
                ans.push_back(it[0]);
                ans.push_back(it[1]);
            }
            else UnionBySize(it[0], it[1]);
        }
        return ans;
    }
};