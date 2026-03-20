class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                cout<<grid[i][j]<<" ";
                vector<int> temp;
                set<int> st;
                for(int i1=i;i1<i+k;i1++){
                    for(int j1=j;j1<j+k;j1++){
                        st.insert(grid[i1][j1]);
                    }
                }
                if(st.size()==1){
                    ans[i][j]=0;
                    break;
                }
                
                for(auto ele:st){
                    temp.push_back(ele);
                }
                int mn=INT_MAX;
                for(int i2=1;i2<temp.size();i2++){
                    int df=abs(temp[i2]-temp[i2-1]);
                    mn=min(mn,df);
                }
                ans[i][j]=mn;
            }
            cout<<endl;
        }       
        return ans;
    }
};