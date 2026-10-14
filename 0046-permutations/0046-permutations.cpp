class Solution {
public:
    void f(int ind,vector<int>& nums,int n,vector<vector<int>> &ans,vector<int> &arr, vector<int> vis){
        if(ind==n){
            ans.push_back(arr);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==1) continue;
            arr.push_back(nums[i]);
            vis[i]=1;
            f(ind+1,nums,n,ans,arr,vis);
            arr.pop_back();
            vis[i]=0;
        }
        

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> arr;
        vector<int> vis(n,0);
        f(0,nums,n,ans,arr,vis);
        return ans;
    }
};