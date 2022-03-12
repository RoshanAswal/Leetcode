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
        if(!head || !k)return head;
        ListNode* temp1=head,*temp2=head,*ex=temp1;
        int c=0;
        while(ex){
            ex=ex->next;
            c++;
        }
        c=k%c;
        if(!c)return head;
        while(c--){
            temp2=temp2->next;
            if(temp2)ex=temp2;
        }
        while(temp2->next){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp2)ex=temp2;
        }
        ListNode* res=temp1->next;
        temp1->next=NULL;
        ex->next=head;
        return res;
    }
};