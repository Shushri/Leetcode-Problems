class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for(int i=c-1;i>0;i--){
            vector<int> d;
            int r1=0;
            int c1=i;
            while(c1<c){
                d.push_back(grid[r1++][c1++]);
            }
            sort(d.begin(),d.end());
            r1=0;
            c1=i;
            int p=0;
            while(c1<c){
                grid[r1++][c1++]=d[p++];
            }
        }
        for(int i=0;i<r;i++){
            vector<int> d;
            int r1=i;
            int c1=0;
            while(r1<r){
                d.push_back(grid[r1++][c1++]);
            }
            sort(d.begin(),d.end(),greater<int>());
            r1=i;
            c1=0;
            int p=0;
            while(r1<r){
                grid[r1++][c1++]=d[p++];
            }
        }
        return grid;
    }
};