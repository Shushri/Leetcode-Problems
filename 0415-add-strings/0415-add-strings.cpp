class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        int i=n1-1;
        int j=n2-1;
        int c=0;
        string ans="";
        while(i>=0 && j>=0){
            int sm=(num1[i--]-'0')+(num2[j--]-'0')+c;
            ans=(char)((sm%10)+'0')+ans;
            c=sm/10;
        }
        while(i>=0 ){
            int sm=(num1[i--]-'0')+c;
            ans=(char)((sm%10)+'0')+ans;
            c=sm/10;
        }
        while( j>=0){
            int sm=(num2[j--]-'0')+c;
            ans=(char)((sm%10)+'0')+ans;
            c=sm/10;
        }
        if(c!=0){
            ans=(char)(c+'0')+ans;
        }
        return ans;


    }
};