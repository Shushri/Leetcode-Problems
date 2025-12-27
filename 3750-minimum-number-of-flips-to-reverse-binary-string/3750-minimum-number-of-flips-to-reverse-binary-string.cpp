class Solution {
public:
    string B2S(int n){
        string s="";
        while(n){
            if(n&1){
                s+='1';
            }
            else{
                s+='0';
            }
            n=n>>1;
        }
        return s;
    } 
    int minimumFlips(int n) {
        string s1=B2S(n);
        string s2=s1;
        reverse(s1.begin(),s1.end());
        int c=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                c++;
            }
        }
        return c;
        
    }
};