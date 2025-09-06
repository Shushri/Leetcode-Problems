class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int sz=n.size();
        int i=0;
        int j=sz-1;
        while(i<j){
            if(n[i]+n[j]==t){
                return {i+1,j+1};
            }
            else if(n[i]+n[j]<t){
                i++;
            }
            else if(n[i]+n[j]>t){
                j--;
            }
             
        }
        return {};
    }
};