class Solution {
public:
    int countPrimes(int n) {
        //sieve of eratosthenes
        vector<int> Prime(n+1,1);
        
        for(int i=2;i*i<=n;i++){
            if(Prime[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    Prime[j]=0;
                }
            }
        }
        int c=0;
        for(int i=2;i<=n;i++){
            if(Prime[i]==1){
                c++;
            }
        }
        return c;

    }
};