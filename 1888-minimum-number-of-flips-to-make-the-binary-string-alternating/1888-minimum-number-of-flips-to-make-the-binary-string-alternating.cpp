class Solution {
public:
    int minFlips(string s) {
        
        int n=s.size();
        s=s+s;
        int mn=INT_MAX;
        int o1=0;
        int o2=0;
        //10101
        int j=0;
        for(int i=0;i<2*n;i++){
            if(i%2==0 && s[i]=='0'){
                o1++;
            }
            if(i%2==1 && s[i]=='1'){
                o2++;
            }
            if(i>=n-1){
                mn=min(mn,o1+o2);
                if(j%2==0 && s[j]=='0'){
                    o1--;
                }
                if(j%2==1 && s[j]=='1'){
                    o2--;
                }  
                j++;
            }
            
        }
        
        int o3=0;
        int o4=0;
        //0101
        j=0;
        for(int i=0;i<2*n;i++){
            if(i%2==0 && s[i]=='1'){
                o3++;
            }
            if(i%2==1 && s[i]=='0'){
                o4++;
            }
            if(i>=n-1){
                mn=min(mn,o3+o4);
                if(j%2==0 && s[j]=='1'){
                    o3--;
                }
                if(j%2==1 && s[j]=='0'){
                    o4--;
                } 
                j++; 
            }
        }
        return mn;
    }
};