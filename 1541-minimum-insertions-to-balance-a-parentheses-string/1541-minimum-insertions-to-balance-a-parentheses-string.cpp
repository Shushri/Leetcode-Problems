class Solution {
public:
    int minInsertions(string s) {

        // need = number of ')' required
        // to balance the '(' seen so far
        int need = 0;

        // Number of insertions required
        int ans = 0;

        for (char c : s) {

            if (c == '(') {

                // Every '(' requires two ')'
                need += 2;

                // If need becomes odd, we have an issue:
                // the previous '(' requires a pair of ')',
                // so insert one ')' before starting this new '('.
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }

            } else {

                // This ')' satisfies one required ')'
                need--;

                // We have an extra ')' with no '(' to match it.
                if (need == -1) {

                    // Insert '(' before this ')'
                    ans++;

                    // That new '(' requires one more ')' later,
                    // because the current ')' satisfies one of its two ')'.
                    need = 1;
                }
            }
        }

        // Insert all remaining required ')'
        ans += need;

        return ans;
    }
};