class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        long long int nn=n;//to handle INT_MIN
        double ans=1.0;
        if(nn<0){
            nn=-1*nn;
        }
        while(nn){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans=ans*x;
                nn=nn-1;
            }
        }
        if(n<0){
            return (double)(1.0)/(double)(ans);
        }
        return ans;
    }
};