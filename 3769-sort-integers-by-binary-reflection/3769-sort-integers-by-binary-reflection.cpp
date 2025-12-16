class Solution {
public:
    string D2B(int n){
        string ans="";
        while(n){
            if(n%2==0){
                ans+='0';
            }
            else{
                ans+='1';
            }
            n=n/2;
        }
        return ans;
    }
    int B2D(string s){
        long long p=1;
        long long ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=p;
            }

            p=p*2;
        }
        return (int)ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> pp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string p=D2B(nums[i]);
            int c=B2D(p);
            pp.push_back({c,nums[i]});
        }
        sort(pp.begin(),pp.end());
        vector<int> anss;
        for(auto i : pp){
            anss.push_back(i.second);
        }
        return anss;
    }
};