class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int nm=i;
            int c=0;
            while(nm){
                nm=(nm&(nm-1));
                c++;
            }
            ans[i]=c;
        }
        return ans;

    }
};