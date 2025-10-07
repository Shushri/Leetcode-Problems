class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        if(n==1){
            return 1;
        }
        int c=0;
        vector<int> ans(n,1);
        
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1]){
                
                ans[i]=ans[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--){
            if(r[i-1]>r[i]){
                ans[i-1]=max(ans[i-1],ans[i]+1);
            }
        }
        int sum=0;
        for(auto ele:ans){
            cout<<ele<<"  ";
            sum+=ele;
        }
        return sum;
    }
};