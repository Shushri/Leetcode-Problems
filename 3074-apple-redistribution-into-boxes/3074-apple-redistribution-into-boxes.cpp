class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        int sm=0;
        for(int i=0;i<a.size();i++){
            sm+=a[i];
        }
        sort(c.begin(),c.end());
        int pp=0;
        int cnt=0;
        for(int i=c.size()-1;i>=0;i--){
            pp+=c[i];
            cnt++;
            if(pp>=sm){
                break;

            }
        }
        return cnt;
    }
};