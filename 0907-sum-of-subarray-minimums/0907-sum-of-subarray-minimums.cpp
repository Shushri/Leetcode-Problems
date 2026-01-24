class Solution {
public:
    int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int  n = arr.size();
        stack<int> st;
        vector<long long> nse(n);
        vector<long long> pse(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nse[st.top()]=n;
            st.pop();
        }


        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){   //important
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            pse[st.top()]=-1;
            st.pop();
        }


        long long ans=0;
        for(int i=0;i<n;i++){
            long long pp=i-pse[i];
            long long nn=nse[i]-i;
            
            ans=(ans+(arr[i]%MOD*nn%MOD*pp%MOD)%MOD)%MOD;
        }
        
        return ans;

    }
};