/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        Node* x=new Node(node->val);
        if(node->neighbors.size()==0){
            return x;
        }
        
        unordered_map<Node*,int> vis;
        vis[node]=1;
        unordered_map<Node*,Node*> mpp;
        mpp[node]=x;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* nd=q.front();
            q.pop();
            
            for(auto it:nd->neighbors){
                
                if(!vis[it]){
                    vis[it]=1;
                    Node* new_nd=new Node(it->val);
                    mpp[nd]->neighbors.push_back(new_nd);
                    mpp[it]=new_nd;
                    q.push(it);

                }
                else{
                    mpp[nd]->neighbors.push_back(mpp[it]);
                }

            }
        }
        return x;

    }
};