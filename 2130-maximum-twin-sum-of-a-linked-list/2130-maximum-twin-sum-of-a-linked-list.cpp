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
    int pairSum(ListNode* h1) {
        ListNode* h2=new ListNode(-1);
        ListNode* temp1=h1;
        ListNode* temp2=h2;
        while(temp1){
            int vl=temp1->val;
            ListNode* nd=new ListNode(vl);
            temp2->next=nd;
            temp2=temp2->next;
            temp1=temp1->next;
        }
        ListNode* prev=NULL;
        temp2=h2->next;
        while(temp2){
            ListNode* nxt=temp2->next;
            temp2->next=prev;
            prev=temp2;
            temp2=nxt;
        }
        temp2=prev;
        temp1=h1;
        int mx=0;
        while(temp1){
            int vl1=temp1->val;
            temp1=temp1->next;
            int vl2=temp2->val;
            temp2=temp2->next;
            mx=max(mx,vl1+vl2);
        }
        return mx;
    }
};