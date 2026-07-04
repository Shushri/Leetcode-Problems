class Solution {
public:
    int magicalString(int n) {
        if(n==1 || n==2 || n==3 ){
            return 1;
        }
        string s="122";
        int ind=2;
        int sz=3;
        int cnt=1;//counts 1
        int p=2;//alternate
        while(sz<n){
            if(p==1){  //last was 1
                if(s[ind]=='1'){
                    s+='2';
                    sz+=1;
                }
                else{
                    s+="22";
                    sz+=2;
                }
                p=2;
            }
            else{
                if(s[ind]=='1'){
                    s+='1';
                    sz+=1;
                    cnt+=1;    
                }
                else{
                    s+="11";
                    
                    if(n-sz>=2){
                        cnt+=2;
                    }
                    else{
                        cnt+=1;
                    }
                    sz+=2;
                }
                p=1;
            }
            ind++;
        }
        return cnt;
    }
};