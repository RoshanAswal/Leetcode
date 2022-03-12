/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* temp=new Node(head->val);
        Node* ans=temp,*headC=head->next;
        while(headC){
            Node* temp1=new Node(headC->val);
            temp->next=temp1;
            temp=temp->next;
            headC=headC->next;
        }
        headC=head;
        temp=ans;
        while(headC){
            if(headC->random){
                Node* data=headC->random;
                Node* to=head,*too=ans;
                while(to && to!=data){
                    to=to->next;      
                    too=too->next;
                }
                if(to)
                    temp->random=too;
            }else
                temp->random=NULL;
            headC=headC->next;
            temp=temp->next;
        }
        return ans;
    }
};