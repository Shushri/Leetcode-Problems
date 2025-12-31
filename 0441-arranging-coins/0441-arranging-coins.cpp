class Solution {
public:
    int arrangeCoins(int n) {
        long long p=1;
        long long s=p*(p+1)/2;
        while(true){
            if(s>n){
                break;
            }
            p++;
            s=p*(p+1)/2;
        }
        return (int)(--p);

        
    }
};