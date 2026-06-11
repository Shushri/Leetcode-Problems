class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> odd(n+1,0);
        int osm=0;
        vector<int> even(n+1,0);
        int esm=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                even[i+1]=esm+nums[i];
                odd[i+1]=odd[i];
                esm+=nums[i];
            }
            else{
                odd[i+1]=osm+nums[i];
                even[i+1]=even[i];
                osm+=nums[i];
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            int lefto=odd[i];
            int lefte=even[i];
            int righto;
            int righte;
            righto=odd[n]-odd[i+1];
            righte=even[n]-even[i+1];

                
            if(lefto+righte==righto+lefte){
                c++;  
            }
            
        }
        return c;
    }
};