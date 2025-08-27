class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int i=0;
        int j=n-1;
        int mxar=0;
        while(i<j){
            mxar=max(mxar,min(h[i],h[j])*(j-i));
            if(h[i]<h[j]){
                i++;
            }
            else{
                j--;
            }
        }  
        return mxar;
    }
};