class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end()); // ascending order
        int h = 0;

        for (int i = 0; i < n; i++) {
            int papers = n - i; // number of papers with at least citations[i] citations
            h = max(h, min(citations[i], papers));
        }

        return h;
    }
};
