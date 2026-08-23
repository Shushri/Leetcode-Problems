struct Node{
    Node* links[2];
    bool flag=false;
    Node(){
        links[0]=NULL;
        links[1]=NULL;
    }
    bool containsKey(int ch){
        if(links[ch]!=NULL) return true;
        return false;
    }
    void put(int ch,Node* node){
        links[ch]=node;

    }
    Node* get(int ch){
        return links[ch];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }

};
class Trie{
    Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                 int bit=(num>>i)&1;
                 
                 if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                 }
                 node=node->get(bit);
            }
            node->setEnd();
        }
        int maxres(int num){
            Node* node = root;
            int mx=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->containsKey(1-bit)){
                    mx=mx|(1<<i);
                    node=node->get(1-bit);
                }
                else{
                    node=node->get(bit);
                }
            }
            return mx;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto ele:nums){
            trie.insert(ele);
        }
        int ans=0;
        for(auto ele:nums){
            int nmm=trie.maxres(ele);
            ans=max(nmm,ans);
        }
        return ans;
    }
};