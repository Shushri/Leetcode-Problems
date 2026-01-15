class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int c=0;
        if(n==0){
            return true;
        }
        if(f.size()==1 && f[0]==0){
                return true;
        }
        for(int i=0;i<f.size();i++){
            if(f[i]==0){
                //1st ele
                if(i==0 && f[i+1]==0){
                    f[i]=1;
                    c++;
                    if(c==n){
                        return true;
                    }
                }
                //last ele
                if(i==f.size()-1 && f[i-1]==0){
                    f[i]=1;
                    c++;
                    if(c==n){
                        return true;
                    }
                }
                //others
                if((i-1)>=0 && (i+1)<f.size() && f[i-1]==0 && f[i+1]==0){
                    f[i]=1;
                    c++;
                    if(c==n){
                        return true;
                    }
                }
            }
        }
        return false;   
    }
};