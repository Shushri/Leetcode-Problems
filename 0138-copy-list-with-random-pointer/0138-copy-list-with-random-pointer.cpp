/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        unordered_map<Node*,Node*> mpp;
        int hd_val=head->val;
        Node* hd=new Node(hd_val);
        mpp[head]=hd;
        Node* temp_orig=head;
        Node* temp_new=hd;
        while(temp_orig){
            if(temp_orig->next!=nullptr){
                int vl=temp_orig->next->val;
                Node* pp=new Node(vl);
                temp_new->next=pp;
            }else{
                temp_new->next=NULL;
            }
            
            temp_orig=temp_orig->next;
            temp_new=temp_new->next;
            mpp[temp_orig]=temp_new;
        }
        temp_orig=head;
        temp_new=hd;
        while(temp_orig){
            if(temp_orig->random!=nullptr ){
                
                Node* pp=mpp[temp_orig->random];
                temp_new->random=pp;
            }
            else{
                temp_new->random=NULL;
            }
            
            temp_orig=temp_orig->next;
            temp_new=temp_new->next;
        }
        return hd;
    }
};