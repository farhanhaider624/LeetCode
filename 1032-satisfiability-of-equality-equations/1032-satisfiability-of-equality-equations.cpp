class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent) return;
        if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
        else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        for(int i=0; i<26; i++){
            parent[i]=i;
        }
        for(auto &it:equations){
            if(it[1]=='='){
                Union(it[0]-'a', it[3]-'a');
            }
        }
        for(auto &it:equations){
            if(it[1]=='!'){
                int u_parent = find(it[0]-'a');
                int v_parent = find(it[3]-'a');
                if(u_parent==v_parent) return false;
            }
        }
        return true;
    }
};