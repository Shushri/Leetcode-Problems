class Solution {
public:
    string convert2bin(int n){
        string ans="";
        while(n){
            if(n%2==0){
                ans+="0";
            }
            else{
                ans+="1";
            }
            n=n/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    bool isPowerOfTwo(int n) {
        string s=convert2bin(n);
        int c=0;
        if(n<0){
            return false;
        }
        for (int i=0;i<s.size();i++){
            if(s[i]=='1'){
                c++;
            }

        }
        if(c==1){
            return true;
        }
        return false;
    }
};