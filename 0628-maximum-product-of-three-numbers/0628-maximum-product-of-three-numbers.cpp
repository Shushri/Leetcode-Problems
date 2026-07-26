class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        int x=INT_MAX,y=INT_MAX;
        for(int i=0;i<n;i++){
            int d=nums[i];
            if(d<x){
                y=x;
                x=d;
            }
            else if(d<y){
                y=d;
            }
            if(d>a){
                c=b;
                b=a;
                a=d;
            }
            else if(d>b){
                c=b;
                b=d;
            }
            else if(d>c){
                c=d;
            }
        }
        long long ans1=a*b*c;
        long long ans2=a*x*y;
        long long ans=ans1>ans2?ans1:ans2;
        return ans;
    }
};