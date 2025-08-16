class Solution {
public:
    int climbStairs(int n) {
        int sum=1;
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        int a=1;
        int b=2;
        sum=a+b;
        for(int i=3;i<n;i++){
            a=b;
            b=sum;
            sum=a+b;
        }
        return sum;
    }
};