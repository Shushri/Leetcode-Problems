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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* tail=nullptr;
        int n=0;
        while(temp){
            n++;
            tail=temp;
            temp=temp->next;
            
        }
        
        
        if(k==0 || !head || !head->next){
            return head;
        }
        tail->next=head;
        k=k%n;
        int c=n-k;
        temp=head;
        ListNode* prev=nullptr;
        while(c>0){
            prev=temp;
            temp=temp->next;

            c--;
        }
        prev->next=nullptr;
        return temp;

    }
};