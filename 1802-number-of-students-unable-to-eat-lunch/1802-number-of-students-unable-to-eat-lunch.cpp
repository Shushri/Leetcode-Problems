class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& san) {
        int n=st.size();
        queue<int> stu;
        stack<int> snd;
        for (int i=0;i<n;i++){
            stu.push(st[i]);
        }
        for (int i=n-1;i>=0;i--){
            snd.push(san[i]);
        }
        int c=0;
        int i=0;

        while(!stu.empty()){
            if(i>n*n){
                break;
            }
            if(snd.top()==stu.front()){
                snd.pop();
                stu.pop();
                c++;
            }
            else{
                int rem=stu.front();
                stu.pop();
                stu.push(rem);
            }
            i++;
            
        }
        return n-c;
    }
};