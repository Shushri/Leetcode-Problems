class Solution {
public:
    int maxProduct(int n) {
        int a=INT_MIN;
        int b=INT_MIN;
        while(n){
            int s=n%10;
            if(s>=a){
                b=a;
                a=s;
            }
            else if(s>b){
                b=s;
            }
            n=n/10;
        }
        return a*b;

    }
};