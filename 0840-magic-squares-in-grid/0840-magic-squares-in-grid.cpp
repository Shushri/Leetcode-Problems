class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                int a1=grid[i][j];
                int a2=grid[i][j+1];
                int a3=grid[i][j+2];
                int b1=grid[i+1][j];
                int b2=grid[i+1][j+1];
                int b3=grid[i+1][j+2];
                int c1=grid[i+2][j];
                int c2=grid[i+2][j+1];
                int c3=grid[i+2][j+2];
                set<int> st;
                st.insert(a1);
                st.insert(a2);
                st.insert(a3);
                st.insert(b1);
                st.insert(b2);
                st.insert(b3);
                st.insert(c1);
                st.insert(c2);
                st.insert(c3);
                if(st.size()==9 && (a1+a2+a3)==(b1+b2+b3) && (b1+b2+b3)==(c1+c2+c3) && (c1+c2+c3)==(a1+b1+c1) && (a1+b1+c1)==(a2+b2+c2) && (a2+b2+c2)==(a3+b3+c3) && (a3+b3+c3)==(a1+b2+c3) && (a1+b2+c3)==(a3+b2+c1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};