class Solution {
public:
   
    int uniquePaths(int m, int n) {
        vector<int> post_row(n,0);
        
        for(int i=m-1;i>=0;i--){
            vector<int> temp(n);
            
            for(int j=n-1;j>=0;j--){
                if(i==m-1 || j==n-1){
                    temp[j]=1;
                }
                else{
                    temp[j]=temp[j+1]+post_row[j];
                }
                
            }
            post_row=temp;
        }
        return post_row[0];
    }
};