class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int df=INT_MAX;
        for(int i=0;i<n-1;i++){
            int ppp=arr[i+1]-arr[i];
            df=min(ppp,df);
        }
        for(int i=0;i<n-1;i++){
            int ppp=arr[i+1]-arr[i];
            if(ppp==df){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};