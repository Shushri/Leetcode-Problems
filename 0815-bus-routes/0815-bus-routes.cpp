class Solution {
public:
    int numBusesToDestination(
        vector<vector<int>>& routes,
        int source,
        int target
    ) {
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> stopToBus;

        // Which buses can be taken from each stop?
        for (int bus = 0; bus < routes.size(); bus++) {
            for (int stop : routes[bus]) {
                stopToBus[stop].push_back(bus);
            }
        }

        queue<pair<int, int>> q;
        unordered_set<int> visitedStop;
        vector<int> visitedBus(routes.size(), 0);

        q.push({source, 0});
        visitedStop.insert(source);

        while (!q.empty()) {
            auto [stop, busesTaken] = q.front();
            q.pop();

            for (int bus : stopToBus[stop]) {

                if (visitedBus[bus])
                    continue;

                visitedBus[bus] = 1;

                for (int nextStop : routes[bus]) {

                    if (nextStop == target)
                        return busesTaken + 1;

                    if (!visitedStop.count(nextStop)) {
                        visitedStop.insert(nextStop);
                        q.push({nextStop, busesTaken + 1});
                    }
                }
            }
        }

        return -1;
    }
};