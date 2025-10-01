class Solution {
public:
    int numWaterBottles(int a, int b) {
        if(a<b){
            return a;
        }
        int ans=a;
        int emp=a;
        while(true){
            if(emp/b==0){
                break;
            }
            ans+=(emp/b);
            emp=(emp%b+emp/b);
        }
        return ans;
    }
};