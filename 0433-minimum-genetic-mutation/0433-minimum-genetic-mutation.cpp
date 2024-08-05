class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st;
        for(auto &it:bank) st.insert(it);
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        char geneChar[]={'A', 'C', 'G', 'T'};
        while(!q.empty()){
            string gene = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(gene==endGene) return steps;
            for(int i=0; i<gene.size(); i++){
                char temp=gene[i];
                for(int j=0; j<4; j++){
                    gene[i]=geneChar[j];
                    if(st.find(gene)!=st.end()){
                        q.push({gene, steps+1});
                        st.erase(gene);
                    }
                }
                gene[i]=temp;
            }
        }
        return -1;
    }
};