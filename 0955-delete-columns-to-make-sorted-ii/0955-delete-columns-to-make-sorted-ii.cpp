class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int k=strs[0].size();
        vector<int> sorted(n,0);
        vector<int> removed(k,0);
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
        int c=0;
        for(int i=0;i<k;i++){
            if(removed[i]){
                c++;
            }
        }
        return c;
    }
};