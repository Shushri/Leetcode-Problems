class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=1;
        int b=n-1;
        for(int i=1;i<n;i++){
            a=i;
            b=n-i;
            int x=a;
            int y=b;
            int c=0;
            while(x){
                int f=x%10;
                if(f==0) c++;
                x=x/10;

            }
            while(y){
                int f=y%10;
                if(f==0) c++;
                y=y/10;
            }
            if(c==0){
                return {a,b};
            }
        }
       
        return {a,b};
    }
};