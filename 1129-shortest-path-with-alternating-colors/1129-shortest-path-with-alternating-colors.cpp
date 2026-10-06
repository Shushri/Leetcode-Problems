class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& re,
        vector<vector<int>>& be
    ) {
        vector<vector<pair<int,char>>> arr(n);

        for (auto &e : re)
            arr[e[0]].push_back({e[1], 'R'});

        for (auto &e : be)
            arr[e[0]].push_back({e[1], 'B'});

        vector<int> visR(n, 0), visB(n, 0);
        vector<int> dis(n, INT_MAX);

        dis[0] = 0;

        queue<pair<int, pair<int, char>>> q;

        q.push({0, {0, 'P'}});

        while (!q.empty()) {

            auto [node, state] = q.front();
            q.pop();

            int d = state.first;
            char clr = state.second;

            for (auto ele : arr[node]) {

                int next = ele.first;
                char nextColor = ele.second;

                // Colors must alternate
                if (clr == nextColor)
                    continue;

                // Reached using RED
                if (nextColor == 'R' && !visR[next]) {

                    visR[next] = 1;
                    dis[next] = min(dis[next], d + 1);

                    q.push({next, {d + 1, 'R'}});
                }

                // Reached using BLUE
                else if (nextColor == 'B' && !visB[next]) {

                    visB[next] = 1;
                    dis[next] = min(dis[next], d + 1);

                    q.push({next, {d + 1, 'B'}});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dis[i] == INT_MAX)
                dis[i] = -1;
        }

        return dis;
    }
};