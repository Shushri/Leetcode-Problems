class Solution {
public:

    vector<long long> dijkstra(
        int src,
        vector<vector<pair<int,int>>> &adj
    ) {
        int n = adj.size();

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            // Ignore outdated entry
            if (d != dist[node])
                continue;

            for (auto [next, weight] : adj[node]) {

                long long newDist = d + weight;

                // Relaxation
                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    pq.push({newDist, next});
                }
            }
        }

        return dist;
    }


    long long minimumWeight(
        int n,
        vector<vector<int>>& edges,
        int src1,
        int src2,
        int dest
    ) {

        vector<vector<pair<int,int>>> adj(n);
        vector<vector<pair<int,int>>> rev(n);

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});

            // Reverse graph
            rev[v].push_back({u, w});
        }

        // Shortest distance from src1 to every node
        vector<long long> d1 = dijkstra(src1, adj);

        // Shortest distance from src2 to every node
        vector<long long> d2 = dijkstra(src2, adj);

        // Shortest distance from every node to dest
        //
        // Run from dest on reversed graph.
        vector<long long> d3 = dijkstra(dest, rev);

        long long ans = LLONG_MAX;

        // Try every node as the meeting point
        for (int i = 0; i < n; i++) {

            // If any part of the path is impossible,
            // this node cannot be the meeting point.
            if (d1[i] == LLONG_MAX ||
                d2[i] == LLONG_MAX ||
                d3[i] == LLONG_MAX)
                continue;

            // src1 → i
            // src2 → i
            // i → dest
            long long total = d1[i] + d2[i] + d3[i];

            ans = min(ans, total);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};