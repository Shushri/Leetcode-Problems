class Solution {
public:
    bool isPerfectSquare(int num) {
         if(num%2==0){
            long long int i=2;
            while(i*i<=(long long int)num){
                if((long long int)num==i*i){
                    return true;
                    break;
                }
                i+=2;

            }
         }
         if(num%2==1){
            long long int i=1;
            while(i*i<=(long long int)num){
                if((long long int)num==i*i){
                    return true;
                    break;
                }
                i+=2;

            }
         }
         return false;
    }
};