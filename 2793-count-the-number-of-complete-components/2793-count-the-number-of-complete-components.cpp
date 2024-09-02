class Solution {
public:
    vector<int> par, size, edgeCount;
    int findUPar(int i) {
        if (i == par[i])
            return i;
        return par[i] = findUPar(par[i]);
    }

    void UnionBySize(int i, int j) {
        int pi = findUPar(i);
        int pj = findUPar(j);

        if (pi != pj) {
            if (size[pi] >= size[pj]) {
                par[pj] = pi;
                size[pi] += size[pj];
                edgeCount[pi] += edgeCount[pj];
            } else {
                par[pi] = pj;
                size[pj] += size[pi];
                edgeCount[pj] += edgeCount[pi];
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        par.resize(n);
        size.resize(n, 1);
        edgeCount.resize(n, 0);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        vector<vector<int>> adjMat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            adjMat[i][i] = 1;
        }
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            UnionBySize(u, v);
            edgeCount[findUPar(u)]++;
        }
        int completeCompt = 0;
        for (int i = 0; i < n; i++) {
            if (par[i] == i) {
                int k = size[i];
                int expectedEdges = (k * (k - 1)) / 2;
                if (edgeCount[i] == expectedEdges)
                    completeCompt++;
            }
        }
        return completeCompt;
    }
};