class Solution {
public:
    int maxDepth(string s) {
        int mx=0;
        int c=0;
        for (auto a:s){
            if(a=='('){
                c++;
            }
            if(a==')'){
                c--;
            }
            mx=max(mx,c);
        }
        return mx;
    }
};