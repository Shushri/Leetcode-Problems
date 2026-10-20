class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;
            bool ok=true;
            for(int i=0;i<n && ok ;i+=k){
                int d=0;
                for(int j=0;j<k-1;j++){
                    if(nums[i+j]>nums[i+j+1]) d++;
                    
                }
                if(nums[i+k-1]>nums[i]) d++;
                if(d>1) ok=false;
                
            }

            for(int i=0;i<n-k && ok; i+=k){
                vector<int> a(nums.begin()+i,nums.begin()+i+k);
                vector<int> b(nums.begin()+i+k,nums.begin()+i+2*k);
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
                if(a.back()>b.front()) ok=false;
            }

            if(ok) ans+=k;
        }
        return ans;
    }
};