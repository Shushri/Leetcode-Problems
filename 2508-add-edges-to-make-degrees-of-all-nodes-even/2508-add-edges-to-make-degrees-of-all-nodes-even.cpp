class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n + 1, 0);
        
        // Use an array of unordered_sets for O(1) edge lookups
        vector<unordered_set<int>> adj(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            deg[u]++;
            deg[v]++;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (deg[i] % 2 != 0) {
                odd.push_back(i);
            }
        }
        
        // Case 0: All nodes already have even degree
        if (odd.empty()) {
            return true;
        }
        
        // It's impossible to fix if odd degree count is not 2 or 4
        if (odd.size() != 2 && odd.size() != 4) {
            return false;
        }
        
        // Case 1: Exactly 2 nodes have odd degrees
        if (odd.size() == 2) {
            int a = odd[0];
            int b = odd[1];
            
            // Try connecting them directly
            if (!adj[a].count(b)) {
                return true;
            }
            
            // If they are already connected, try finding an intermediate node 'i'
            for (int i = 1; i <= n; i++) {
                if (i != a && i != b && !adj[a].count(i) && !adj[b].count(i)) {
                    return true;
                }
            }
            return false;
        }
        
        // Case 2: Exactly 4 nodes have odd degrees
        if (odd.size() == 4) {
            int a = odd[0];
            int b = odd[1];
            int c = odd[2];
            int d = odd[3];
            
            // Try the 3 possible ways to pair up the 4 nodes
            if (!adj[a].count(b) && !adj[c].count(d)) return true;
            if (!adj[a].count(c) && !adj[b].count(d)) return true;
            if (!adj[a].count(d) && !adj[b].count(c)) return true;
            
            return false;
        }
        
        return false;
    }
};