class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        for(int i=0;i<n;i++){
            long long req=(success+spells[i]-1)/spells[i];
            auto it=lower_bound(potions.begin(),potions.end(),req);
            spells[i]=potions.end()-it;
        }
        return spells;
    }
};