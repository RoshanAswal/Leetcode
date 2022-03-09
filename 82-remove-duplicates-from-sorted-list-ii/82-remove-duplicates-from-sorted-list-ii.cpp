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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode* temp = head,*root=head,*ans=NULL;
        int prev=head->val;
        while(temp){
            int c=0;
            ListNode* rootTemp;
            while(temp && temp->val==prev){
                rootTemp=temp;   
                temp=temp->next;
                c++;
            }
            if(temp)
                prev=temp->val;
            if(c==1){
                if(!ans){
                    root=rootTemp;
                    ans=root;
                    root->next=NULL;
                }else{
                    root->next=rootTemp;   
                    root=root->next;
                    root->next=NULL;
                }
            }
        }
        return ans;
    }
};