class Solution {
public:
    int addDigits(int num) {
        while(num/10!=0){
            int pp=num;
            int sm=0;
            while(pp){
                int a=pp%10;
                pp=pp/10;
                sm+=a;
            }
            num=sm;
        }
        return num;
    }
};