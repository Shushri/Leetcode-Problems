class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int one = 0;
        string ans = "";
        for (int j = 0; j < n; j++) {
            if (s[j] == '1')
                one++;
            while (one >= k) {
                while (i <= j && s[i] == '0')
                    i++;
                string curr = s.substr(i, j - i + 1);

                if (ans == "" ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }

                one--;
                i++;
            }
        }

        return ans;
    }
};