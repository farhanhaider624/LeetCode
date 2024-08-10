class Solution {
public:
    vector<int> ans;
    unordered_map<string, int> mp;
    void dfs(int curr, int parent, vector<int> adj[], vector<int> &result, string &labels, vector<int> &count){
        char currLabel = labels[curr];
        int cnt_before = count[currLabel-'a'];
        count[currLabel-'a']+=1;
        for(auto child:adj[curr]){
            if(child!=parent){
                dfs(child, curr, adj, result, labels, count);
            }
        }
        int cnt_after = count[currLabel-'a'];
        result[curr]=cnt_after-cnt_before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        vector<int> adj[n];
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> result(n, 0);
        vector<int> count(26, 0);    

        dfs(0, -1, adj, result, labels, count);

        return result;    
    }
};