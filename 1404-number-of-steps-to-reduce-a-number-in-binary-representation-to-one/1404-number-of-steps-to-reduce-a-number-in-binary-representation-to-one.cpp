class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int e=0;
        int o=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                
                if(o==0){
                    if(i==0){
                        break;
                    }
                    ans+=2;
                    o=1;
                }
                else{
                    ans++;
                }
            }
            else{
                if(o==1){
                    ans+=2;
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
    }
};
//10011
//10100