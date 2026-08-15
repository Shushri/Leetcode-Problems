class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ans=0;
        while(c){
            int nc,nb,na;
            if((c&1)==1){
                nc=1;
            }
            else{
                nc=0;
            }
            if((b&1)==1){
                nb=1;
            }
            else{
                nb=0;
            }
            if((a&1)==1){
                na=1;
            }
            else{
                na=0;
            }
            if(nc==0 ){
                if(na==1 && nb==1){
                    ans+=2;
                }
                else if(na==1 || nb==1){
                    ans++;
                }
            }
            if(nc==1 ){
                if(na==0 && nb==0){
                    ans++;
                }
                
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;

        }
        while(b){
            b=b&(b-1);
            ans++;
        }
        while(a){
            a=a&(a-1);
            ans++;
        }
        return ans;

    }
};