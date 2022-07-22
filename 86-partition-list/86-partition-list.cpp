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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)return head;
        ListNode *s=new ListNode();
        ListNode *g=new ListNode();
        ListNode *temp=head,*ss=s,*gg=g;
        while(temp){
            if(temp->val>=x){
                g->next=temp;
                g=g->next;
            }else{
                s->next=temp;
                s=s->next;
            }
            temp=temp->next;
        }
        g->next=NULL;
        s->next=gg->next;
        return ss->next;
    }
};