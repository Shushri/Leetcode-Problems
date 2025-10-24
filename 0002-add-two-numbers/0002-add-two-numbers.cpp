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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int > n1;
        vector<int > n2;
        vector<int > n3;
        ListNode* temp=l1;
        
        while(temp!=nullptr){
            n1.push_back(temp->val);
            temp=temp->next;
        }

        temp=l2;
        while(temp!=nullptr){
            n2.push_back(temp->val);
            temp=temp->next;
        }
        int c=0;
        int i=0;
        while(i<n1.size() && i<n2.size()){
            int sm=n1[i]+n2[i]+c;
            
            n3.push_back(sm%10);
            c=sm/10;
            i++;
            
        }
        while(i<n1.size()){
            int sm=n1[i]+c;
            n3.push_back(sm%10);
            c=sm/10;
            i++;
        }
        while(i<n2.size()){
            int sm=n2[i]+c;
            n3.push_back(sm%10);
            c=sm/10;
            i++;
        }
        if(c>0){
            n3.push_back(c);
        }
        ListNode* ans = new ListNode(n3[0]);
        ListNode* curr = ans;

        for(int i=1;i<n3.size();i++){
            curr->next=new ListNode(n3[i]);
            curr=curr->next;    
        }
        return ans;


    }
};