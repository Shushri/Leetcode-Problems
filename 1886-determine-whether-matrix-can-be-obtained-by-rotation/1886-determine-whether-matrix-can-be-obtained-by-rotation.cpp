class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        if(mat==target){
            return true;
        }
        
        int f1=0;
        for(int i=0;i<n;i++){
            vector<int> temp=mat[n-i-1];
            reverse(temp.begin(),temp.end());
            if(temp!=target[i]){
                f1=1;
                break;
            }
        }
        if(f1==0){
            return true;
        }

        vector<vector<int>> mat2(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat2[j][n-i-1]=mat[i][j];
            }
        }
        if(mat2==target){
            return true;
        }
        int f2=0;
        for(int i=0;i<n;i++){
            vector<int> temp=mat2[n-i-1];
            reverse(temp.begin(),temp.end());
            if(temp!=target[i]){
                f2=1;
                break;
            }
        }
        if(f2==0){
            return true;
        }
        
        return false;
    }
};