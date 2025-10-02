class Solution {
public:
    int maxBottlesDrunk(int a, int b) {
        if(b>a){
            return a;
        }
        int ans=a;
        int e=a;
        int f=0;
        while(e>=b){
            e=e-b;
            
            f++;
            e++;
            b++;
        }
        return ans+f;
    }
};