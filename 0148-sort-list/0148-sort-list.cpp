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
    ListNode* merge(ListNode* h1,ListNode* h2){
        ListNode* temp;
        ListNode* head;
        if(!h1) return h2;
        if(!h2) return h1;
        if(h1->val<h2->val){
            temp=h1;
            head=temp;
            h1=h1->next;
        }
        else{
            temp=h2;
            head=temp;
            h2=h2->next;
        }
        
        while(h1 && h2){
            if(h1->val<h2->val){
                temp->next=h1;
                h1=h1->next;
                temp=temp->next;

            }
            else{
                temp->next=h2;
                h2=h2->next;
                temp=temp->next;
            }
        }
        if(h1){
            temp->next=h1;
        }
        if(h2){
            temp->next=h2;
        }
        return head;
    }
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* ms(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* mid=middle(head);
        ListNode* mm=mid->next;
        mid->next=nullptr;
        ListNode* left=ms(head);
        ListNode* right=ms(mm);
        return merge(left,right);

    }
    ListNode* sortList(ListNode* head) {
        return ms(head);
    }
};