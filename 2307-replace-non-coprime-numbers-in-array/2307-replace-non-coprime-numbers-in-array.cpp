class Solution {
public:
    int hcf_nm(int n, int m) {
        while (m != 0) {
            int temp = m;
            m = n % m;
            n = temp;
        }
        return n;
    }

    long long lcm_mn(long long m, long long n) {
        int hh = hcf_nm(m, n);
        return (m / hh) * n;  // safe from overflow
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;  // stack to hold merged numbers

        for (long long x : nums) {
            st.push_back(x);
            // keep merging as long as top 2 are non-coprime
            while (st.size() > 1) {
                long long a = st.back();
                long long b = st[st.size() - 2];
                long long g = hcf_nm(a, b);
                if (g == 1) break; // coprime, stop merging
                st.pop_back();
                st.pop_back();
                st.push_back(lcm_mn(a, b));
            }
        }

        // convert back to int
        return vector<int>(st.begin(), st.end());
    }
};
