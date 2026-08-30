class DisJoint {
public:
    vector<int> parent, size;

    DisJoint(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = find(parent[u]);
    }

    void UnionbySize(int u, int v) {
        int ultu = find(u);
        int ultv = find(v);

        if (ultu == ultv)
            return;

        if (size[ultu] < size[ultv])
            swap(ultu, ultv);

        parent[ultv] = ultu;
        size[ultu] += size[ultv];
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //2n because we are taking the enemies opposites from n+1 to 2n
        //n=5
        //opposite of 1 is 6 , 2 is 7 and 5 is 10
        DisJoint D(2 * n + 1);

        for (auto &edge : dislikes) {

            int u = edge[0];
            int v = edge[1];

            // u and v cannot be in the same group
            if (D.find(u) == D.find(v))
                return false;

            // u must be opposite to v
            D.UnionbySize(u, v + n);
            D.UnionbySize(v, u + n);
        }

        return true;
    }
};