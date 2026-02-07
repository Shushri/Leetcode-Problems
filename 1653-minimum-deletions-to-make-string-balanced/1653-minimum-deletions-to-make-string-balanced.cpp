class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<pair<int,int>> ab(n);
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
            }
            else{
                b++;
            }
            ab[i]={a,b};
        }   
        if(b==n || a==n){
            return 0;
        }
        int ans=INT_MAX;
        
        
        for(int i=0;i<n;i++){
            int bb=ab[i].second;
            int aa=ab[n-1].first-ab[i].first;
            ans=min(ans,(aa+bb));
        }
        if(a<ans || b<ans){
            return min(a,b);
        }
        return ans;
    }
};