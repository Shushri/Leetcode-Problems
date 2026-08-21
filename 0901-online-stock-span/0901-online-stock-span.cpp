class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int j=i;
        while(!st.empty() && price>=st.top().second){
            
            st.pop();
        }
        if(!st.empty() ) j=st.top().first+1;
        else{
            j=0;
        }
        int ans=i-j+1;
        st.push({i,price});
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */