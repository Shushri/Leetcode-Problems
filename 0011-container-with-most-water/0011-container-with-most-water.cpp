class Solution {
public:
    int maxArea(vector<int>& height) {
        int  n=height.size();
        int l=0;
        int h=n-1;
        int mx=0;

        while(l<h){
            mx=max(mx,min(height[l],height[h])*(h-l));
            if(height[l]<height[h]){
                l++;
            }
            else{
                h--;
            }
        }
        return mx;
    }
};