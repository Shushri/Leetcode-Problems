class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        int k=strs.size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<k;j++){
                if(strs[j][i]<strs[j-1][i]){
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};