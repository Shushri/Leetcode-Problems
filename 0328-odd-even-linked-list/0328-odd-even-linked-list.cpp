/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return head;
        }
        ListNode* odd=head;
        ListNode* o=odd;
        
        ListNode* even=head->next;
        ListNode* e=even;
        ListNode* temp=head->next->next;
        int i=0;
        while(temp){
            if(i==0){
                o->next=temp;
                
                o=o->next;
                i=1;
            }
            else{
                e->next=temp;
                e=e->next;
                i=0;
            }
            temp=temp->next;
        }
        e->next=NULL;
        o->next=even;
        return odd;


    }
};