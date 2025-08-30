class Solution {
public:
    int convert(int num, int n) {
        string s = "";
        
        // Convert number to binary string
        while (num) {
            s += (num % 2 == 0 ? '0' : '1');
            num /= 2;
        }
        reverse(s.begin(), s.end());

        // Pad with leading zeros to length n
        while ((int)s.size() < n) {
            s = "0" + s;
        }

        // Build Gray code binary string
        string ans = "";
        ans += s[0];
        for (int i = 1; i < n; i++) {
            ans += (s[i] == s[i-1] ? '0' : '1');
        }

        // Convert binary string back to integer
        int ppp = 0;
        int p = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (ans[i] == '1') {   // ✅ FIXED HERE
                ppp += p;
            }
            p *= 2;
        }
        return ppp;
    }

    vector<int> grayCode(int n) {
        int cnt = 1 << n;   // 2^n
        vector<int> bin;
        bin.reserve(cnt);   // ✅ avoids extra zeros

        for (int i = 0; i < cnt; i++) {
            bin.push_back(convert(i, n));
        }
        return bin;
    }
};
