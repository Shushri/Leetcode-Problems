class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int> mpp;
        for(int i=0;i<n;i++){
            vector<int> arr;
            for(int j=0;j<n;j++){
                arr.push_back(grid[j][i]);
            }
            mpp[arr]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mpp.count(grid[i])>0){
                ans+=mpp[grid[i]];
            }
        }
        return ans;

    }   
};