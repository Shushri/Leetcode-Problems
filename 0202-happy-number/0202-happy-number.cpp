class Solution {
public:
    bool isHappy(int n) {
        int i=0;
        if(n==1){
            return true;
        }
        while(n!=1){
            int a=0;
            if(i>=10){
                return false;
            }
            while(n){
                
                int f=n%10;
                n=n/10;
                a=a+f*f;
                
            }
            n=a;
            if(n==1){
                return true;
            }
            i++;
        }
        
        return false;
    }
};