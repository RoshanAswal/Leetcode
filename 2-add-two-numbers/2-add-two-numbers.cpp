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
        int carry=0,ans=0,mul=1;
        ListNode* l=l1,*r=l2,*res=NULL,*re;
        while(l && r){
            int sum=(l->val+r->val)+carry;
            carry=sum/10;
            ans=sum%10;
            mul=10;
            l=l->next;
            r=r->next;
            ListNode* temp=new ListNode(ans);
            if(!res){
                res=temp;
                re=res;
            }
            else{
                res->next=temp;
                res=res->next;
            }
        }
        while(l){     
            int sum=l->val+carry;
            carry=sum/10;
            ans=sum%10;
            ListNode* temp=new ListNode(ans);
            res->next=temp;
            res=res->next;
            l=l->next;
        }
        while(r){     
            int sum=r->val+carry;
            carry=sum/10;
            ans=sum%10;
            ListNode* temp=new ListNode(ans);
            res->next=temp;
            res=res->next;
            r=r->next;
        }
        if(carry){
            ListNode* temp=new ListNode(carry);
            res->next=temp;
        }
        return re;
    }
};