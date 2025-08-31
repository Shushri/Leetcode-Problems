class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>> red;
        vector<vector<int>> yel;
        for(int i=0;i<r;i+=2){
            int r1=i;
            int c1=0;
            vector<int> d;
            while(r1>=0 && c1<c){
                d.push_back(mat[r1--][c1++]);

            }
            red.push_back(d);

        }
        
        for(int i=r&1?2:1;i<c;i+=2){
            int r1=r-1;
            int c1=i;
            vector<int> d;
            while(c1<c && r1>=0){
                d.push_back(mat[r1--][c1++]);

            }
            red.push_back(d);
            
        }
        // for(auto ele:red){
        //     for(auto a:ele){
        //         cout<<a<<" ";
        //     }
        // }
        // cout<<endl;

        for(int i=1;i<c;i+=2){
            int r1=0;
            int c1=i;
            vector<int> d;
            while(c1>=0 && r1<r){
                d.push_back(mat[r1++][c1--]);

            }
            yel.push_back(d);

        }
        for(int i=c&1?1:2;i<r;i+=2){
            int r1=i;
            int c1=c-1;
            vector<int> d;
            while(r1<r && c1>=0){
                d.push_back(mat[r1++][c1--]);

            }
            yel.push_back(d);
            
        }
        // for(auto ele:yel){
        //     for(auto a:ele){
        //         cout<<a<<" ";
        //     }
        // }
        // cout<<endl;
        vector<int> ans;
        for(int i=0;i<red.size();i++){
            if(i<red.size()){
                    for(int j=0;j<red[i].size();j++){
                           ans.push_back(red[i][j]);
                    }
            }
            if(i<yel.size()){
                    for(int j=0;j<yel[i].size();j++){
                            ans.push_back(yel[i][j]);
                    }
            }
            
            
            
        }
        return ans;

    }
};