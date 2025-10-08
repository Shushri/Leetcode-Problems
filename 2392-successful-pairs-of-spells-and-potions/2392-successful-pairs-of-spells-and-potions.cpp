class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;

        for (int spell : spells) {
            long long need = (success + spell - 1) / spell; 
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ans.push_back(potions.end() - it);
        }
        return ans;
    }
};
