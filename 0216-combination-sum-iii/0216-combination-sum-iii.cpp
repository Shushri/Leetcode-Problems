class Solution {
public:
    void f(int ind,int k,int n,vector<int> &arr,vector<int> temp,vector<vector<int>> &ans){
        if(ind==9){
            if(n==0 && k==0){
                ans.push_back(temp);
            }
            return ;
        }

        if(arr[ind]<=n){
            temp.push_back(arr[ind]);
            f(ind+1,k-1,n-arr[ind],arr,temp,ans);
            temp.pop_back();
        }
        f(ind+1,k,n,arr,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,k,n,arr,temp,ans);
        return ans;
    }
};