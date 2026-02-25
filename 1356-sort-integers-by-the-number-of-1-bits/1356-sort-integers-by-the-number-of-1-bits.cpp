class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int pp=__builtin_popcount(arr[i]);
            v.push_back({arr[i],pp});
        }
        


        sort(v.begin(),v.end(),[](auto &a,auto &b){
            if(a.second==b.second){
                return a.first<=b.first;
            }
            return a.second<=b.second;
        });

        vector<int> ans;
        for(auto ele:v){
            ans.push_back(ele.first);
        }
        return ans;



    }
};