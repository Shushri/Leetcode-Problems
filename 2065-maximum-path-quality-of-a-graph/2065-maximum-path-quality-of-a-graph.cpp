class Solution {
public:
    int ans = 0;

    void dfs(int node, int time, int quality,
             vector<int>& values,
             vector<vector<pair<int,int>>>& graph,
             vector<int>& visited,
             int maxTime) {

        // We can only take the answer when we are back at node 0
        if (node == 0) {
            ans = max(ans, quality);
        }

        for (auto [next, edgeTime] : graph[node]) {

            if (time + edgeTime > maxTime)
                continue;

            bool firstVisit = (visited[next] == 0);

            if (firstVisit)
                quality += values[next];

            visited[next]++;

            dfs(next, time + edgeTime, quality,
                values, graph, visited, maxTime);

            visited[next]--;

            if (firstVisit)
                quality -= values[next];
        }
    }

    int maximalPathQuality(vector<int>& values,
                           vector<vector<int>>& edges,
                           int maxTime) {

        int n = values.size();

        vector<vector<pair<int,int>>> graph(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];

            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        vector<int> visited(n, 0);
        visited[0] = 1;

        dfs(0, 0, values[0], values, graph,
            visited, maxTime);

        return ans;
    }
};