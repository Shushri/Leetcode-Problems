class Solution {
public:
    const int MOD=1e9+7; 
    string b2S(int n){
        string ans="";
        while(n){
            if(n%2==1){
                ans+='1';
            }
            else{
                ans+='0';
            }
            n=n/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int concatenatedBinary(int n) {
        string num="";
        for(int i=1;i<=n;i++){
            num+=b2S(i);
        }
        int nn=num.size();
        long long ans=0;
        long long p=1;
        for(int i=nn-1;i>=0;i--){
            if(num[i]=='1'){
                ans=(ans+p)%MOD;
            }
            p=(p*2)%MOD;
        }
        return ans;
    }
};