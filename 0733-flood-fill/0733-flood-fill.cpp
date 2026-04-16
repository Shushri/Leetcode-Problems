class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int clr=image[sr][sc];
        if(clr==color){
            return image;
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                pair<int,int> nd=q.front();
                q.pop();
                int r=nd.first;
                int c=nd.second;
                image[r][c]=color;
                if(r-1>=0 && image[r-1][c]==clr){
                    //image[r-1][c]=color;
                    q.push({r-1,c});
                }
                if(c-1>=0 && image[r][c-1]==clr){
                    //image[r][c-1]=color;
                    q.push({r,c-1});
                }
                if(r+1<n && image[r+1][c]==clr){
                    //image[r+1][c]=color;
                    q.push({r+1,c});
                }
                if(c+1<m && image[r][c+1]==clr){
                    //image[r][c+1]=color;
                    q.push({r,c+1});
                }
            }
        }
        return image;
    }
};