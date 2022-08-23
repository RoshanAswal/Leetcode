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
    bool isPalindrome(ListNode* head) {
        if(!head->next || !head)return true;
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;fast=fast->next->next;
        }
        ListNode* pre=NULL,*curr=slow->next,*nxt=slow->next->next;
        while(curr){
            curr->next=pre;
            pre=curr;
            curr=nxt;
            if(nxt)nxt=nxt->next;
        }
        while(pre){
            if(head->val!=pre->val)return false;
            head=head->next;pre=pre->next;
        }
        return true;
    }
};