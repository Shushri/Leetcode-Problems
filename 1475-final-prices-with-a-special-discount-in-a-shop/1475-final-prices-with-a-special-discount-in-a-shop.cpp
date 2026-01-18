class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        
        int n=p.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(p[j]<=p[i]){
                    p[i]=p[i]-p[j];
                    break;
                }
            }
        }
        return p;
    }
};