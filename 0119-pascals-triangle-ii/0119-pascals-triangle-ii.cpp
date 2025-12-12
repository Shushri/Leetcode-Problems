class Solution {
public:
    
    vector<int> getRow(int r) {
        vector<int> ans(r+1);
        ans[0]=1;
        ans[r]=1;
        long long int p=1;
        for(int i=1;i<r;i++){
            p=p*(r-i+1)/i;
            
            ans[i]=p;
        }
        return ans;
    }
};