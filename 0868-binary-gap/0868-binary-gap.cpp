class Solution {
public:
    int binaryGap(int n) {
        int c=0;
        int p=-1;
        int ans=0;
        while(n){
            if((n&(1))==1){
                if(p==-1){
                    ans=0;
                }
                else{
                    ans=max(ans,(c+1-p));

                }
                p=c+1;
            }
            c=c+1;
            n=n>>1;
        }
        return ans;
    }
};