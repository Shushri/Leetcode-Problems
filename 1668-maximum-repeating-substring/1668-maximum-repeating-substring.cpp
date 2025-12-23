class Solution {
public:
    int maxRepeating(string seq, string word) {
        int n=seq.size();
        int k=word.size();
        int ans=0;
        int mx=0;
        for(int i=0;i<=(n-k);i++){
            //cout<<i<<"   ";
            if(word==seq.substr(i,k)){
                ans++;
                i=i+k-1;
                
            }
            
            else{
                if(ans>0){
                    i=i-k;
                    mx=max(ans,mx);
                    ans=0;
                }
                else{

                }
            }
        }
        mx=max(ans,mx);
        return mx;
    }
};