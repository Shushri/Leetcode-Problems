class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int pr=1;
            int nm=n;
            while(n){
                int c=n%10;
                n=n/10;
                pr*=c;
            }
            
            if(pr%t==0){
                return nm;
            }
            n=nm+1;
            pr=1;
        }
        return 1;
    }
};