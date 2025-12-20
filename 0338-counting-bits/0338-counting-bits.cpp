class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0){
            return {0};
        }
        if(n==1){
            return {0,1};
        }
        vector<int> ans(n+1);
        ans[0]=0;
        ans[1]=1;
        int c=0;
        for(int i=2;i<=n;i++){
            if((i & (i-1))==0){
                c=i;
                
            }
            
            ans[i]=ans[i-c]+1;
        }
        return ans;
    }
};
//0
//0 1
//0 1 1
//0 1 1 2
//0 1 1 2 1
//0 1 1 2 1 2