class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long ans=0;
        int n=p.size();
        int c=1;
        for(int i=1;i<n;i++){
            if(p[i-1]-p[i]==1){
                c++;
            }
            else{
                ans+=(long long)c*(long long)(c+1)/2;
                c=1;
            }
        }
        ans+=(long long)c*(long long)(c+1)/2;
        return ans;
    }
};