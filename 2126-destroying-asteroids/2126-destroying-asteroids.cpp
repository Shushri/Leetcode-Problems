class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        long long ans=mass;
        for(int i=0;i<ast.size();i++){
            if(ast[i]>ans){
                return false;
            }
            else{
                ans+=ast[i];
            }
        }
        return true;
    }
};