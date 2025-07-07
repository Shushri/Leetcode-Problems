class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        long long int nn=n;
        if(n<0){
            
            nn=-1*nn;
            x=1/x;
        }
        double ans=myPow(x,nn/2);
        if(nn%2==0){
            return ans*ans;
        }
        else{
            return x*ans*ans;
        }
    }
};