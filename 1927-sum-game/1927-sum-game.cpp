class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int sm1=0;
        int sm2=0;
        int q1=0;
        int q2=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') q1++;
            else sm1+=(num[i]-'0');
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') q2++;
            else sm2+=(num[i]-'0');
        }
        if(q1==0 && q2==0 ){
            if(sm1==sm2){
                return false;
            }
            return true;
        }
        if((q1+q2)%2==1){
            return true;
        }

        if((sm1-sm2)==((q2-q1)/2)*9){
            return false;
        }
        return true;

    }
};
//alice
//nums  even length
//alice hlf sums not eql
//bob hlf sums eql
//alice wins... true else false
//9=x1+x2+x3-x0
//10=x1+x2