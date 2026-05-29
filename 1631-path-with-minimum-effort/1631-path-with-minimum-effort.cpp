class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        dis[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(d > dis[i][j]) continue;

            for(int k = 0; k < 4; k++) {
                int rw = i + dr[k];
                int cl = j + dc[k];

                if(rw >= 0 && rw < n && cl >= 0 && cl < m) {
                    int df = abs(h[i][j] - h[rw][cl]);
                    int newEffort = max(d, df);

                    if(newEffort < dis[rw][cl]) {
                        dis[rw][cl] = newEffort;
                        pq.push({newEffort, {rw, cl}});
                    }
                }
            }
        }

        return dis[n-1][m-1];
    }
};