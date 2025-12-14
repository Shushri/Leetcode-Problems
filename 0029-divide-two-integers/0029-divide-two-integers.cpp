class Solution {
public:
    int divide(int divi, int di) {
        if(divi==INT_MIN && di==-1){
            return INT_MAX;
        }
        long long ans=0;
        int sign=1;
        long long div=divi;
        long long d=di;
        if(div<0 && d>0){
            sign = -1;
        }
        else if(div>=0 && d<0){
            sign = -1;
        }
        else{
            sign=1;
        }

        div=abs(div);
        d=abs(d);

        while(div>=d){
            int c=0;
            while(div>=d*1<<c){
                c++;
            }
            ans+=1<<c-1;
            div-=d*1<<c-1;

        }
        
        return ans*sign;
    }
};