class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            int dis=j-i;
            int ar=dis*min(h[i],h[j]);
            ans=max(ans,ar);
            if(h[i]<h[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};