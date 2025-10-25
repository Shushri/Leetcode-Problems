class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        unordered_set<char> seen;
        int left = 0;  // left boundary of window

        for (int right = 0; right < n; right++) {
            // If s[right] is already in the set, shrink window from left
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            // Add new character to the window
            seen.insert(s[right]);

            // Update maximum length found so far
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
