class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;        
        for(auto ele:tokens){
            if(ele=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a+b;
                st.push(c);
            }
            else if(ele=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b-a;
                st.push(c);
            }
            else if(ele=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a*b;
                st.push(c);
            }
            else if(ele=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b/a;
                st.push(c);
            }
            else{
                int num=0;
                for(int i=0;i<ele.size();i++){
                    if(ele[i]=='-'){
                        continue;
                    }
                    num=num*10+(int)(ele[i]-'0');
                }
                
                if(ele[0]=='-'){
                    
                    num=num*(-1);
                }
                st.push(num);
            }
            if(!st.empty()) cout<<st.top()<<endl;
        } 
        return st.top();
    }
};