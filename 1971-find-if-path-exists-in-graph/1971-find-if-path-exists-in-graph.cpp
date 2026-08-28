class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = find(parent[u]);
    }

    void unionfn(int u, int v) {

        int upu = find(u);
        int upv = find(v);

        if (upu == upv)
            return;

        if (rank[upu] > rank[upv]) {
            parent[upv] = upu;
        }
        else if (rank[upu] < rank[upv]) {
            parent[upu] = upv;
        }
        else {
            parent[upu] = upv;
            rank[upv]++;
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        DisjointSet D(n);

        for (auto &edge : edges) {
            D.unionfn(edge[0], edge[1]);
        }

        return D.find(source) == D.find(destination);
    }
};