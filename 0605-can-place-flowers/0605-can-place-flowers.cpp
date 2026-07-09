class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int sz=fb.size();
        int c=0;
        
        for(int i=0;i<sz;i++){
            if(i==0) {
                if(fb[i]==0   ){
                    if(i+1<sz){
                        if(fb[i+1]==0){
                        fb[0]=1;
                        c++;}
                    }
                    else {
                        fb[0]=1;
                        c++;
                    }
                    
                }
                continue;
            }
            if(i==sz-1) {
                if(i-1>=0 && fb[i]==0 && fb[i-1]==0 ){
                    fb[i]=1;
                    c++;
                   
                }
                 continue;
            }
            if(fb[i]==0 && fb[i-1]==0 && fb[i+1]==0){
                fb[i]=1;
                c++;
            }
        }
        if(c>=n) return true;
        return false;
    }
};