class Solution {
public:
    int maximalRectangle(vector<vector<char>>& m) {
        int r=m.size();
        int c=m[0].size();
        vector<vector<int>> a(r,vector<int>(c));
        for(int i=0;i<c;i++){
            int sm=0;
            for(int j=0;j<r;j++){
                if(m[j][i]=='1'){
                    sm++;
                    a[j][i]=sm;
                }
                else{
                    sm=0;
                    a[j][i]=sm;
                }
            }
        }
        int ans=0;
        // for(auto ele:a){
        //     for(auto el2:ele){
        //         cout<<el2<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<r;i++){
            stack<int> st;
            for(int j=0;j<=c;j++){
                int ht=j==c?0:a[i][j];
                while(!st.empty() && ht<a[i][st.top()]){
                    int tp=st.top();
                    st.pop();
                    int wd=!st.empty()?j-st.top()-1:j;
                    int ar=wd*a[i][tp];
                    ans=max(ans,ar);
                }
                st.push(j);
            }
        }

        return ans;
    }
};