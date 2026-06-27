class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            ans = (freq[1] % 2 ? freq[1] : freq[1] - 1);
        }

        for (auto &[start, _] : freq) {
            if (start == 1) continue;

            long long x = start;
            int len = 0;

            while (freq[x] >= 2) {
                len += 2;

                
                if (x > 1000000000LL) break;

                long long nxt = x * x;
                if (!freq.count(nxt)) break;

                x = nxt;
            }

            if (freq[x] == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};