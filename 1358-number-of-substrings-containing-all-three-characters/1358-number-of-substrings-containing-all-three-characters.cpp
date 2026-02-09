class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr(3);
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            arr[s[j]-'a']++;
            while(arr[0]>=1 && arr[1]>=1 && arr[2]>=1){
                ans+=(n-j);
                arr[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};