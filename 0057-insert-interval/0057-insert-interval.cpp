class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& ninv) {
        int spos=inv.size();
        int s=0;
        int epos=inv.size();
        int e=0;
        if(inv.size()==0){
            return {ninv};
        }
        for(int i=0;i<inv.size();i++){
            if(ninv[0]<inv[i][0]){
                spos=i;
                s=0;
                break;
            }
            else if(ninv[0]>=inv[i][0] && ninv[0]<=inv[i][1]){
                spos=i;
                s=1;
                break;
            }
        }
        for(int i=0;i<inv.size();i++){
            if(ninv[1]<inv[i][0]){
                epos=i;
                e=0;
                break;
            }
            else if(ninv[1]>=inv[i][0] && ninv[1]<=inv[i][1]){
                epos=i;
                e=1;
                break;
            }
        }
        if(s==1 && e==1){
            if(spos==epos){
                return inv;
            }
            else{
                int l=inv[epos][1];
                inv.erase(inv.begin()+spos+1,inv.begin()+epos+1);
                inv[spos][1]=l;
                return inv;
            }
        }
        else if(s==0 && e==1){
            if(spos==epos){
                inv[spos][0]=ninv[0];
                return inv;
            }
            else{
                int l=inv[epos][1];
                inv.erase(inv.begin()+spos+1,inv.begin()+epos+1);
                inv[spos][1]=l;
                inv[spos][0]=ninv[0];
                return inv;
            }
        }
        else if(s==1 && e==0){
            
                
                inv.erase(inv.begin()+spos+1,inv.begin()+epos);
                inv[spos][1]=ninv[1];
                
                return inv;
            
        }
        else{

            if(spos==epos){
                inv.insert(inv.begin()+spos,ninv);
                return inv;
            }
            else{
                inv.erase(inv.begin()+spos+1,inv.begin()+epos);
                inv[spos][0]=ninv[0];
                inv[spos][1]=ninv[1];
                return inv;
            }

        }
        return inv;

    }
};