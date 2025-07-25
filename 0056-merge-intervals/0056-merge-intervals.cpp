class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        
        sort(i.begin(),i.end(),[](vector<int> a,vector<int> b){
            return a[0]<b[0];
        });
    vector<vector<int>> ans={{i[0][0],i[0][1]}};
    int k=0;
    for (int j=1;j<i.size();j++){
            
            if(ans[k][1]>=i[j][0]){
                int mx=max(i[j][1],ans[k][1]);
                ans[k][1]=mx;
            }
            else{
                ans.push_back({i[j][0],i[j][1]});
                k++;
                
            }
            
        }
        
    return ans;
    }
};