class Solution {
public:
    int minArrivalsToDiscard(vector<int>& ar, int w, int m) {
        int n=ar.size();
        unordered_map<int , int> mpp;
        vector<int> mark(n);
        int c=0;
        for(int i=0;i<n;i++){
            
            if(i>=w && mpp[ar[i-w]]!=0 && mark[i-w]!=-1){
                mpp[ar[i-w]]--;
                mark[i]=0;
            }
            
            
            if(mpp[ar[i]]<m){
                mpp[ar[i]]++;
                mark[i]=1;
            }
            else{
                c++;
                mark[i]=-1;
            }
        }
        return c;
    }
};