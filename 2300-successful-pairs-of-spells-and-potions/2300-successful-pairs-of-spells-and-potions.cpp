class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        for(int i=0;i<n;i++){
            long long req=(success+spells[i]-1)/spells[i];
            int l=0;
            int h=potions.size()-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(potions[mid]>=req){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            spells[i]=potions.size()-l;
        }
        return spells;
    }
};