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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* f=l1,*s=l2,*fs,*ss;
    if(l1==NULL)return l2;
    else if(l2==NULL)return l1;
    else if(l1==NULL && l2==NULL)return l1;
    if(l1->val>l2->val)std::swap(l1,l2);
    ListNode* res=l1;
        while(l1!=NULL && l2!=NULL){
            ListNode* tmp=NULL;
            while(l1!=NULL && l1->val<=l2->val){
                tmp=l1;
                l1=l1->next;
            }
            tmp->next=l2;
            std::swap(l1,l2);
        }
        return res;
    }
};