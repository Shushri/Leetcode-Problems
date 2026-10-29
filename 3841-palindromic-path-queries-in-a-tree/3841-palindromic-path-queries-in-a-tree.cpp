
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        }

        // XOR update on [l, r]
        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n);
        vector<int> pref(n, 0), parent(n, -1);
        vector<int> order;
        order.reserve(n);

        // Iterative DFS: build Euler order and prefix masks.
        vector<pair<int, int>> st;
        st.push_back({0, 0});
        parent[0] = 0;

        int timer = 0;

        while (!st.empty()) {
            auto& [u, state] = st.back();

            if (state == 0) {
                tin[u] = ++timer;
                order.push_back(u);

                up[0][u] = parent[u];
                for (int j = 1; j < LOG; j++)
                    up[j][u] = up[j - 1][up[j - 1][u]];

                pref[u] = (parent[u] == u ? 0 : pref[parent[u]])
                          ^ (1 << (s[u] - 'a'));

                state = 1;
            }

            if (state <= (int)adj[u].size()) {
                int v = adj[u][state - 1];
                state++;

                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back({v, 0});
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }

        Fenwick fw(n);

        auto getPrefix = [&](int u) {
            return pref[u] ^ fw.query(tin[u]);
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            stringstream ss(q);
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int delta = (1 << (s[u] - 'a'))
                          ^ (1 << (c - 'a'));

                fw.rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;

                int w = lca(u, v);

                int mask = getPrefix(u)
                         ^ getPrefix(v)
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
