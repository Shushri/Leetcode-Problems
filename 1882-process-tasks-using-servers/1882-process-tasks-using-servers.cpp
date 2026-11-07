
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // {weight, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        // {freeTime, {weight, index}}
        priority_queue<
            pair<long long, pair<int,int>>,
            vector<pair<long long, pair<int,int>>>,
            greater<pair<long long, pair<int,int>>>
        > busy;

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;

        for(int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release all servers that have become available
            while(!busy.empty() && busy.top().first <= time) {
                auto ele = busy.top().second;
                available.push(ele);
                busy.pop();
            }

            // If no server is available, jump to earliest free time
            if(available.empty()) {
                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {
                    available.push(busy.top().second);
                    busy.pop();
                }
            }

            // Assign the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans[i] = index;

            // Mark server as busy
            busy.push({
                time + tasks[i],
                {weight, index}
            });
        }

        return ans;
    }
};
