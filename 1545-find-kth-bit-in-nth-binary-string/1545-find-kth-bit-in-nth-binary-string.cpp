class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        if(n==1){
            return '0';
        }
        for(int i=2;i<=n;i++){
            string p="";
            for(int i=0;i<s.size();i++){
                if(s[i]=='1'){
                    p+="0";
                }
                else{
                    p+="1";
                }
            }
            reverse(p.begin(),p.end());
            s=s+'1'+p;
            
        }
        
        char ans;
        for(int i=0;i<s.size();i++){
            if(i==k-1){
                ans=s[i];
            }
        }
        return ans;

    }
};