class Solution {
public:
    bool search(vector<int>& a, int t) {
        for (int i=0;i<a.size();i++){
            if(t==a[i]){
                return true;
            }
        }
        return false;
    }
};