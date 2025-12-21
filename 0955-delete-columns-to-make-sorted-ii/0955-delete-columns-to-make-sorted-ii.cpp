class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int k=strs[0].size();
        bitset<100> sorted=0;
        bitset<100> removed=0;
        for(int i=0;i<k;i++){
            for(int j=0;j<n-1;j++){
                if(!sorted[j] && strs[j][i]>strs[j+1][i]){
                    removed[i]=1;
                    break;
                }
            }
            if (removed[i]) continue;

            for(int j=0;j<n-1;j++){
                if(strs[j][i]<strs[j+1][i]){
                    sorted[j]=1;
                }
            }
        }
        
        return removed.count();
    }
};