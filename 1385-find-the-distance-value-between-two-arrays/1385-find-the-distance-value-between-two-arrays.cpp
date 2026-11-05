class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1=arr1.size();
        int n2=arr2.size();
        int ans=0;
        for(int i=0;i<n1;i++){
            int f=0;
            for(int j=0;j<n2;j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    f=1;
                    
                }
            }
            if(f==0){
                ans++;
            }
        }
        return ans;
    }
};

//4 5 8
//1 8 9 10