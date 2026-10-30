
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dis(n, vector<int>(k + 1, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dis[0][1] = 0;
        pq.push({0, {0, 1}});

        while(!pq.empty()) {

            auto [wt, state] = pq.top();
            pq.pop();

            int nd = state.first;
            int cnt = state.second;

            if(wt != dis[nd][cnt])
                continue;

            if(nd == n - 1)
                return wt;

            for(auto neb : adj[nd]) {

                int ndd = neb.first;
                int wtt = neb.second;

                int newCnt;

                if(labels[nd] == labels[ndd])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if(newCnt > k)
                    continue;

                if(wt + wtt < dis[ndd][newCnt]) {

                    dis[ndd][newCnt] = wt + wtt;

                    pq.push({
                        wt + wtt,
                        {ndd, newCnt}
                    });
                }
            }
        }

        return -1;
    }
};
