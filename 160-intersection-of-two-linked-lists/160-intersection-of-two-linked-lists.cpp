/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* fast=headA,*slow=headB;
        while(fast!=slow){
            if(fast==slow)return slow;
            if(!fast)fast=headA;
            else fast=fast->next;
            if(!slow)slow=headB;
            else slow=slow->next;
        }
        return fast;
    }
};