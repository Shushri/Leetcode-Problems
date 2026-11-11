class Solution {
public:
    long long minimumCost(int c11, int c22, int cBB, int n11, int n22) {
        long long ans=LLONG_MAX;
        long long c1=c11;
        long long c2=c22;
        long long cB=cBB;
        long long n1=n11;
        long long n2=n22;
        if(cB<=min(c1,c2)){
            ans=cB*max(n1,n2);
        }
        if(cB>=max(c1,c2)){
            long long pp=c1*n1+c2*n2;
            ans=min(ans,pp);
            pp=cB*max(n1,n2);
            ans=min(ans,pp);
            if(n1>=n2){
                long long dif=n1-n2;
                pp=dif*c1+cB*n2;
                ans=min(ans,pp);
            }
            else{
                long long dif=n2-n1;
                pp=dif*c2+cB*n1;
                ans=min(ans,pp);
            }
        }
        if(cB>c1 && cB<c2){
            ans=cB*n2;
            if(n1>n2){
                long long df=n1-n2;
                ans+=c1*df;
            }
        }
        if(cB>c2 && cB<c1){
            ans=cB*n1;
            if(n2>n1){
                long long df=n2-n1;
                ans+=c2*df;
            }
        }
        return ans;
    }
};