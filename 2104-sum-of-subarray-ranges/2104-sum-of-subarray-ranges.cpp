class Solution {
public:

    long long subArrayRanges(vector<int>& arr) {
        int  n = arr.size();
        stack<int> st;
        vector<long long> nse(n);
        vector<long long> pse(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
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
            while(!st.empty() && arr[i]<arr[st.top()]){   //important
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
            
            ans=(ans+(arr[i]*nn*pp));
        }

        vector<long long> nge(n);
        vector<long long> pge(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            nge[st.top()]=n;
            st.pop();
        }


        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>arr[st.top()]){   //important
                pge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            pge[st.top()]=-1;
            st.pop();
        }




        long long ans2=0;
        for(int i=0;i<n;i++){
            long long pp=i-pge[i];
            long long nn=nge[i]-i;
            
            ans2=(ans2+(arr[i]*nn*pp));
        }
        
        return ans2-ans;

  
    }
};