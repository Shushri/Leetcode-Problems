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
                vector<int> st;
                vector<int> st2={1,2,3,4,5,6,7,8,9};
                st.push_back(a1);
                st.push_back(a2);
                st.push_back(a3);
                st.push_back(b1);
                st.push_back(b2);
                st.push_back(b3);
                st.push_back(c1);
                st.push_back(c2);
                st.push_back(c3);
                sort(st.begin(),st.end());
                if(st==st2 && (a1+a2+a3)==(b1+b2+b3) && (b1+b2+b3)==(c1+c2+c3) && (c1+c2+c3)==(a1+b1+c1) && (a1+b1+c1)==(a2+b2+c2) && (a2+b2+c2)==(a3+b3+c3) && (a3+b3+c3)==(a1+b2+c3) && (a1+b2+c3)==(a3+b2+c1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};