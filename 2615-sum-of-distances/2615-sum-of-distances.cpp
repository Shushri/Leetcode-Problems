class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        long long n=nums.size();
        unordered_map<long long,vector<long long>> mpp;
        for(long long i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        vector<long long> ans(n);
        for(auto ele:mpp){
            vector<long long> ind=ele.second;
            long long m=ind.size();
            vector<long long> presm(m);
            vector<long long> postsm(m);
            presm[0]=ind[0];
            for(long long i=1;i<m;i++){
                presm[i]=ind[i]+presm[i-1];
            }
            postsm[m-1]=ind[m-1];
            for(long long i=m-2;i>=0;i--){
                postsm[i]=ind[i]+postsm[i+1];
            }
            for(long long i=0;i<m;i++){
                long long p=0;
                if(i-1>=0){
                    p+=i*ind[i]-presm[i-1];
                }
                if(i+1<m){
                    p+=postsm[i+1]-(m-i-1)*ind[i];
                }
                ans[ind[i]]=p;
            }




        }
        return ans;
    }
};

//0,2,3
// presm=0,2,5
// postsm=5,5,3