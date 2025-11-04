class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        unordered_map<int,int> mppp;
        for(int i=0;i<k;i++){
            mppp[nums[i]]++;
        }
        int l=0;
        int h=k-1;
        vector<int> ans;
        while(h<n){
            vector<pair<int,int>> mpp(mppp.begin(),mppp.end());
            sort(mpp.begin(),mpp.end(),[](auto a,auto b){
                if(a.second==b.second){
                    return a.first>b.first;
                }
                return a.second>b.second;
            });
            int cnt=0;
            int sm=0;
            for(auto ele:mpp){
                if(cnt==x){
                    break;
                }
                sm+=ele.first*ele.second;
                cnt++;
            }
            ans.push_back(sm);
            mppp[nums[l]]--;
            if(mppp[nums[l]]==0) mppp.erase(nums[l]);
            l++;
            h++;
            if(h<n){
                mppp[nums[h]]++;
            }
        }
        return ans;
    }
};