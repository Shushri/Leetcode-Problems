class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (int i = 0; i < logs.size(); i++) {
            string log = logs[i];

            // ---- parse id ----
            int idx = 0, id = 0;
            while (log[idx] != ':') {
                id = id * 10 + (log[idx] - '0');
                idx++;
            }

            // ---- check start or end ----
            idx++; // move after first ':'
            bool start = (log[idx] == 's');

            // ---- parse timestamp ----
            int j = log.size() - 1;
            int time = 0, p = 1;
            while (log[j] != ':') {
                time += (log[j] - '0') * p;
                p *= 10;
                j--;
            }

            // ---- logic ----
            if (start) {
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } else {
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};
