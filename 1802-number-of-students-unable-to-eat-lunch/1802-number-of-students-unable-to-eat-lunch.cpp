class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& san) {
        int n=st.size();
        queue<int> stu;
        
        for (int i=0;i<n;i++){
            stu.push(st[i]);
        }
        int j=0;
        int c=0;
        int i=0;

        while(!stu.empty() && i<stu.size()){
            
            if(san[j]==stu.front()){
                
                stu.pop();
                j++;
                c++;
                i=0;
            }
            else{
                int rem=stu.front();
                stu.pop();
                stu.push(rem);
                i++;
            }
            
            
        }
        return n-c;
    }
};