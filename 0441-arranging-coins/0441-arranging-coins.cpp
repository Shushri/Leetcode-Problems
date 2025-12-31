class Solution {
public:
    int arrangeCoins(int n) {
        long long s=floor(sqrt(1LL*2*n));
        long long  p=s*(s+1)/2;
        long long q=(s-1)*(s)/2;
        if(p<=(long long)n){
            return (int)s; 
        }
        else{
            return (int)s-1;
        }

        
    }
};