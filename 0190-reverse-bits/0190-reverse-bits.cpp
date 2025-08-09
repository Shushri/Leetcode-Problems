class Solution {
public:
    string D2B(int n){
        string ans="";
        while(n){
            if(n%2==0){
                ans+='0';
            }
            else{
                ans+='1';
            }
            n=n/2;
        }
        int left=32-ans.size();
        while(left--){
            ans+='0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int B2D(string s){
        int ans=0;
        long long int p2=1;
        for (int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ans+=p2;
            }
            p2=2*p2;
        }
        return ans;
    }
    int reverseBits(int n) {
        string s=D2B(n);
        int ans= B2D(s);
        return ans;;
    }
};