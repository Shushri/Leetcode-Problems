class Solution {
public:
    int maxNumberOfFamilies(int r, vector<vector<int>>& rs) {
        int n=rs.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[rs[i][0]-1].push_back(rs[i][1]-1);
        }
        int ans=0;
        int sz=mpp.size();
        ans+=(r-sz)*2;
        for(auto ele:mpp){
            vector<int> temp(10,0);
            for(auto x:ele.second){
                temp[x]=1;
            }
            if(temp[1]==0 && temp[2]==0 && temp[3]==0 && temp[4]==0){
                ans++;
                temp[1]=1;
                temp[2]=1;
                temp[3]=1;
                temp[4]=1;
            }
            if(temp[3]==0 && temp[4]==0 && temp[5]==0 && temp[6]==0){
                ans++;
                temp[5]=1;
                temp[6]=1;
                temp[3]=1;
                temp[4]=1;
            }
            if(temp[5]==0 && temp[6]==0 && temp[7]==0 && temp[8]==0){
                ans++;
                temp[5]=1;
                temp[6]=1;
                temp[7]=1;
                temp[8]=1;
            }

        }
        return ans;

    }
};