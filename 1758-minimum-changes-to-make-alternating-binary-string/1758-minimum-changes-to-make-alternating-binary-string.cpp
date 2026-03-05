class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int o1=0;
        int o2=0;
        //10101
        for(int i=0;i<n;i+=2){
            if(s[i]=='0'){
                o1++;
            }
        }
        for(int i=1;i<n;i+=2){
            if(s[i]=='1'){
                o2++;
            }
        }
        int o3=0;
        int o4=0;
        //0101
        for(int i=0;i<n;i+=2){
            if(s[i]=='1'){
                o3++;
            }
        }
        for(int i=1;i<n;i+=2){
            if(s[i]=='0'){
                o4++;
            }
        }
        return min(o1+o2,o3+o4);
    }
};