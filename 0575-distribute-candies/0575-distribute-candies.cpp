class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        int n=candyType.size();
        
        sort(candyType.begin(),candyType.end());
        int distinct=1;
        for(int i=1;i<n;i++){
            if(candyType[i-1]!=candyType[i]){
                distinct++;
            }
        }
        if(distinct<=n/2){
            return distinct;
        }
        return n/2;
    }
};