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
        vector<int> dir={0,1,0,-1};
        vector<int> dic={1,0,-1,0};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                pair<int,int> nd=q.front();
                q.pop();
                int r=nd.first;
                int c=nd.second;
                image[r][c]=color;
                for(int j=0;j<4;j++){
                    int rw=r+dir[j];
                    int cl=c+dic[j];
                    if(rw>=0 && rw<n && cl>=0 && cl<m && image[rw][cl]==clr){
                        q.push({rw,cl});
                    }
                }
            }
        }
        return image;
    }
};