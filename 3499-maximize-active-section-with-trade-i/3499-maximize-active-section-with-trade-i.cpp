class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int> arr;
        int i;
        int ones=0;
        for(int p=0;p<n;p++){
            if(s[p]=='1'){
                ones++;
            }
        }
        if(ones==0 || ones==n) return ones;

        for(i=0;i<n;i++){
            if(s[i]=='0'){
                break;
            }
        }
        int oc=0;
        int zc=0;
        for(i;i<n;i++){
            if(s[i]=='1'){
                oc++;
                if(zc>0){arr.push_back(zc);
                zc=0;}
            }
            else{
                zc++;
                if(oc>0){arr.push_back(oc);
                oc=0;}
            }
        }

        if(zc>0){arr.push_back(zc);
            zc=0;
        }
        int mx=ones;
        for(int j=0;j<arr.size();j+=2){
            if(j+1<arr.size()){
                int cnt=ones-arr[j+1];//convert to 0
                cnt+=arr[j]+arr[j+1]+arr[j+2];
                mx=max(mx,cnt);

            }
        }
        return mx;
    }
};